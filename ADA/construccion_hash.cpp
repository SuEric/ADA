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
    TablaHash tablaHash(1003);
    tablaHash.construirTabla();
    return 0;
}

