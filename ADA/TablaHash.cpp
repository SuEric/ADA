//
//  TablaHash.cpp
//  ADA
//
//  Created by sueric on 04/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#include "TablaHash.h"

TablaHash::TablaHash() {
    tam = 100;
    tabla.reserve(tam);
    
    for (int i = 0; i < tam; i++)
        tabla[i] = *new Lista();
}

TablaHash::TablaHash(int _tam) {
    tam = _tam;
    tabla.reserve(tam);
    
    for (int i = 0; i < tam; i++)
        tabla[i] = *new Lista();
}

TablaHash::~TablaHash() {
}

int TablaHash::h(string llave) {
    int i, sum;
    for (sum=0, i=0; llave[i] != '\0'; i++)
        sum += (int) llave[i];
    return sum % tam;
}

void TablaHash::agregar(string _palabra, string _documentos) {
    int indice = h(_palabra);
    tabla[indice].insertarOrd(_palabra, _documentos);
}

void TablaHash::mostrarLista(string llave) {
    int indice = h(llave);
    tabla[indice].imprimir();
}

void TablaHash::borrarIndice(string llave) {
    int indice = h(llave);
    tabla[indice].borrarLista();
}

void TablaHash::construirTabla() {
    DIR *dirp;
    struct dirent *entry;
    
    if( (dirp = opendir("textos")) != NULL) {
        while ((entry = readdir(dirp)) != NULL) {
            if (!strcmp (entry->d_name, ".") ||
                !strcmp (entry->d_name, "..") ||
                !strcmp (entry->d_name, ".DS_Store")) continue;
            if (entry->d_type == DT_REG) {
                char ruta_absoluta[] = "textos/";
                // Lee todo el archivo
                string str(entry->d_name);
                std::ifstream ifs(strcat(ruta_absoluta, entry->d_name));
                std::string texto((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
                regex reg("[^a-zA-Z\\s]+");
                texto = regex_replace(texto, reg, "");
                
                string sentence = " ";
                istringstream iss(texto);
                
                // Crea vector de palabras separadas con espacio
                vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
                
                locale loc;
                vector<string>::iterator it = tokens.begin();
                vector<string>::const_iterator itEnd = tokens.end();
                
                // Minusculas todas
                for (; itEnd != it; ++it) {
                    transform(it->begin(), it->end(), it->begin(),
                              bind1st(mem_fun(&ctype<char>::tolower),
                                      &use_facet< ctype<char> >(loc)));
                }
                
                for (int i = 0; i < tokens.size(); i++)
                    tabla[h(tokens[i])].insertarOrd(tokens[i], str);
                
                string nombre;
                for (int i = 0; i < tam; i++) {
                    nombre = to_string(i) + ".txt";
                    tabla[i].guardarArchivo(nombre);
                }
            }
        }
    }
    else {
        perror("Error abriendo directorio: ");
        exit(1);
    }
}

void TablaHash::mostrarElemento(string llave) {
    int indice = h(llave);
    cout << "Archivo: " << indice << ".txt" << endl;
    
    Nodo *encontrado = tabla[indice].buscar(llave);
    
    if (encontrado != NULL) {
        cout << "\\n\nLa palabra --- " << encontrado->palabra << " --- Se encuentra en los documentos: " <<  endl;
        cout << "\t" << encontrado->documentos << endl;
    }
    else {
        cout << "No se encontró la palabra en ningun documento" << endl;
    }
}

void TablaHash::guardarTablaIndice(string llave) {
    int indice = h(llave);
    tabla[indice].guardarArchivo(to_string(indice) + ".txt");
}

void TablaHash::cargarTablaIndice(string llave) {
    int indice = h(llave);
    tabla[indice].cargarArchivo(to_string(indice) + ".txt");
}