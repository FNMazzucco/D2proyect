#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "EstructuraGrafo23.h"
#include "APIG23.h"


//funciones para extraer datos del grafo. u32 debe estar definida en el .h de arriba

u32 NumeroDeVertices(Grafo G){
    assert (G != NULL);
    return G->num_vertices;
}

u32 NumeroDeLados(Grafo G){
    assert (G != NULL);
    return G->num_lados;
}

u32 Delta(Grafo G){
    assert (G != NULL);
    return G->delta;
}


//funciones de extraccion de informacion de vertices 

u32 Nombre(u32 i,Grafo G){
    assert (G != NULL);
    assert (i < G->num_vertices);

    return G->vertices[i].nombre;
}

u32 Grado(u32 i,Grafo G){
    assert (G != NULL);
    
    if (i >= G->num_vertices)
    {
        return __UINT32_MAX__;
    }
    return G->vertices[i].grado;
}

u32 IndiceVecino(u32 j,u32 i,Grafo G){
    assert (G != NULL);
    if (i >= G->num_vertices || j >= G->vertices[i].grado)
    {
        return __UINT32_MAX__;
    }
    return G->vertices[i].vecinos[j];
}
