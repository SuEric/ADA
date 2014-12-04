//
//  Nodo.cpp
//  ADA
//
//  Created by sueric on 04/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#include "Nodo.h"

// Constructor vacio
Nodo::Nodo() {
    palabra = "";
    documentos = "";
    sig = NULL;
}

// Constructor argumento
Nodo::Nodo(string _palabra, string _documentos) {
    palabra = _palabra;
    documentos = _documentos;
    sig = NULL;
}

// Eliminar todos los nodos
void Nodo::borrarNodo() {
    if (sig)
        sig->borrarNodo();
    delete this;
}

// Imprimir un Nodo
void Nodo::imprimir() {
    //cout << "Nodo-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << sig << endl;
    cout << palabra << "[" << documentos << "]" << "-> ";
}

Nodo::~Nodo() {}