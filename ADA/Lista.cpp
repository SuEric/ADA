//
//  Lista.cpp
//  ADA
//
//  Created by sueric on 04/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#include "Lista.h"

using namespace std;

// Constructor por defecto
Lista::Lista() {
    inicio = NULL;
}

// Insertar de manera ordenada
void Lista::insertarOrd(string palabra, string documentos) {
    Nodo *nuevo_nodo = new Nodo (palabra, documentos);
    
    if (!inicio) {
        inicio = nuevo_nodo;
    }
    else {
        Nodo *encontrado = buscar(palabra);
        if (encontrado != NULL) {
            if(!existeDocumento(encontrado, documentos)) {
                encontrado->documentos = encontrado->documentos + " " + documentos;
            }
        }
        else {
            if (inicio->palabra > palabra) {
                nuevo_nodo->sig = inicio;
                inicio = nuevo_nodo;
            } else {
                Nodo *temp = inicio;
                while ((temp->sig != NULL) && (temp->sig->palabra < palabra)) {
                    temp = temp->sig;
                }
                nuevo_nodo->sig = temp->sig;
                temp->sig = nuevo_nodo;
            }
        }
    }
}

bool Lista::existeDocumento(Nodo *nodo, string documento) {
    string sentence = " ";
    istringstream iss(nodo->documentos);
    
    // Crea vector de palabras separadas con espacio
    vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
    
    bool encontrado = false;
    int i = 0;
    while (i < tokens.size() && !encontrado) {
        if(tokens[i] == documento)
            encontrado = true;
        i++;
    }
    
    if (!encontrado)
        return false;
    return true;
}

// Eliminar todos los nodos
void Lista::borrarLista() {
    inicio = NULL;
    inicio = 0;
}

// Imprimir la Listaa
void Lista::imprimir() {
    Nodo *temp = inicio;
    if (!inicio) {
        cout << "La Listaa está vacía " << endl;
    } else {
        while (temp) {
            temp->imprimir();
            if (!temp->sig) cout << "NULL";
            temp = temp->sig;
        }
    }
    cout << endl << endl;
}

Nodo *Lista::buscar(string palabra) {
    Nodo *temp = inicio;
    
    while (temp != NULL) {
        if (temp->palabra == palabra)
            return temp;
        temp = temp->sig;
    }
    return NULL;
}

// Ordenar de manera ascendente
void Lista::ordenar() {
    string temp_palabra;
    string temp_documentos;
    Nodo *aux = inicio;
    Nodo *temp = aux;
    
    while (aux) {
        temp = aux;
        
        while (temp->sig) {
            temp = temp->sig;
            
            if (aux->palabra > temp->palabra) {
                temp_palabra = aux->palabra;
                temp_documentos = aux->documentos;
                aux->palabra = temp->palabra;
                aux->documentos = temp->documentos;
                temp->palabra = temp_palabra;
                temp->documentos = temp_documentos;
            }
        }
        
        aux = aux->sig;
    }
}

// Cargar una Listaa desde un archivo
void Lista::cargarArchivo(string file) {
    string cadena;
    ifstream in;
    in.open(file.c_str());

    
    if (!in.is_open()) {
        cout << "No se puede abrir el archivo: " << file << endl << endl;
    } else {
        string documentos = "";
        string palabra;
        in >> palabra;
        while (in >> cadena) {
            if(cadena.find(".txt") == string::npos) {
                insertarOrd(palabra, documentos);
                palabra = cadena;
                documentos = "";
            }
            else documentos = documentos + " " + cadena;
        }
        insertarOrd(palabra, documentos);
    }
    in.close();
}

void Lista::guardarArchivo(string file) {
    Nodo *temp = inicio;
    ofstream out;
    out.open(file.c_str());
    
    if (!out.is_open()) {
        cout << "No se puede guardar el archivo " << endl;
    } else {
        while (temp) {
            out << temp->palabra;
            out << " ";
            out << temp->documentos;
            out << " ";
            temp = temp->sig;
        }
    }
    out.close();
}

Lista::~Lista() {}