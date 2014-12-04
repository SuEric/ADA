//
//  Nodo.h
//  ADA
//
//  Created by sueric on 04/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#ifndef __ADA__Nodo__
#define __ADA__Nodo__

#include <iostream>
using namespace std;

class Nodo {
public:
    Nodo();
    Nodo(string, string);
    ~Nodo();
    
    Nodo *sig;
    string palabra;
    string documentos;
    
    void borrarNodo();
    void imprimir();
};

#endif /* defined(__ADA__Nodo__) */
