//
//  main.cpp
//  ADA
//
//  Created by sueric on 01/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#include <iostream>
#include <string>

#include "TablaHash.h"

using namespace std;

int main(int argc, const char * argv[])
{
    cout << "--- Recuperación de información ADA ---\n" << endl;
    cout << "--- MENU ---" << endl;
    cout << "1.- Consultar palabra" << endl;
    cout << "2.- Salir" << endl;
    
    string palabra;
    TablaHash tablaHash(1003);
    int op;
    do {
        cin >> op;
        switch (op) {
            case 1:
                cout << "Ingrese palabra: ";
                cin >> palabra;
                tablaHash.borrarIndice(palabra);
                tablaHash.cargarTablaIndice(palabra);
                tablaHash.mostrarElemento(palabra);
                break;
            case 2:
                cout << "ADIOS!!!" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                exit(1);
                break;
        }
    } while (op != 2);

    return 0;
}

