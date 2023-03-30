#ifndef ESTRUCTURAGRAFO_H
#define ESTRUCTURAGRAFO_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;

typedef struct VerticeSt //Esta estructura guarda informacion de un vertice.
{
    u32 nombre;
    u32 grado;
    u32 *vecinos; 
} VerticeSt;
    
typedef struct GrafoSt //Estructura que sirve para guardar el grafo propiamente dicho.
{
    u32 num_vertices;
    u32 num_lados;
    u32 delta;
    VerticeSt vertices[];   
} GrafoSt;

#endif