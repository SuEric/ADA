//
//  TablaHash.h
//  ADA
//
//  Created by sueric on 04/07/14.
//  Copyright (c) 2014 SuEric. All rights reserved.
//

#ifndef __ADA__TablaHash__
#define __ADA__TablaHash__

#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>
#include <vector>
#include <dirent.h>

#include "Lista.h"

using namespace std;

class TablaHash {
public:
    TablaHash();
    TablaHash(int);
    ~TablaHash();
    void construirTabla();
    void borrarIndice(string);
    int h(string);
    void agregar(string, string);
    void mostrarLista(string);
    void mostrarElemento(string);
    void guardarTablaIndice(string);
    void cargarTablaIndice(string);
private:
    vector<Lista> tabla;
    int tam;
};

#endif /* defined(__ADA__TablaHash__) */
