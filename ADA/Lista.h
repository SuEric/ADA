//
//  Listaa.h
//  ADA
//
//  Created by sueric on 04/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#ifndef __ADA__Listaa__
#define __ADA__Listaa__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include <stdlib.h>

#include "Nodo.h"

class Lista {
public:
    Lista();
    ~Lista();
    
    void insertarOrd(string, string);
    void imprimir();
    Nodo *buscar(string);
    bool existeDocumento(Nodo*, string);
    void guardarArchivo(string);
    void cargarArchivo(string);
    void borrarLista();
    void ordenar();
private:
    Nodo *inicio;
};

#endif /* defined(__ADA__Listaa__) */
