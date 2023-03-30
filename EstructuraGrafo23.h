#ifndef ESTRUCTURAGRAFO_H
#define ESTRUCTURAGRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;
/*
    VerticeST
    Esta estructura guarda informacion de un vertice
*/

typedef struct VerticeSt
{
    u32 nombre;
    u32 grado;
    u32 *vecinos; 
} VerticeSt;

/*  GrafoSt
    Estructura que sirve para guardar el grafo propiamente dicho.
*/

typedef struct GrafoSt
{
    u32 vertices;
    u32 lados;
    u32 delta;
    VerticeSt vertices[];   
} GrafoSt;

#endif