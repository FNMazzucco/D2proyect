#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "EstructuraGrafo23.h"
#include "APIG23.h"

//funciones auxiliares para qsort

static int cmp(const void *_a, const void *_b)
{
	const u32 *a = _a;
	const u32 *b = _b;
	if (a[0] < b[0] || (a[0] = b[0] && a[1] < b[1]))
    	return -1;
    if (a[0] > b[0] || (a[0] = b[0] && a[1] > b[1]))
		return 1;
	return 0;
}

//funcioes de lectura del grafo

static u32 *Lectura(u32 * n, u32 * m)
{
	char c;
	int res;
	// Salteamos comentarios
	res = scanf("%c", &c);
	if (res != 1)
		return NULL;
	while (c == 'c') {
		res = scanf("%*[^\n] ");	// Solo guardamos esto porque sino gcc se queja
		res = scanf("%c", &c);
		if (res != 1)
			return NULL;
	}
	if (c != 'p')
		return NULL;
	// Fin de comentarios, encontramos la 'p', debe seguir " edge n m"
	res = scanf(" edge %" PRIu32 " %" PRIu32, n, m);
	if (res != 2)
		return NULL;
	// Siguen los lados, pedimos memoria para leerlos
	u32 *lados = malloc(*m * 2 * sizeof(u32));
	if (lados == NULL)
		return NULL;

	for (size_t i = 0; i < *m * 2; i += 2) {
		res =
		    scanf(" e %" PRIu32 " %" PRIu32, &lados[i], &lados[i + 1]);
		if (res != 2) {
			free(lados);
			return NULL;
		}
	}
	return lados;

}


//funciones de costrucion y destruccion de grafo

Grafo ConstruccionDelGrafo()
{
    u32 *lados, n, m;
	lados = Lectura(&n, &m);
	if (lados == NULL)
		return NULL;
	// Terminamos lectura. Creamos nuestro grafo.
	Grafo g = malloc(sizeof(GrafoSt) + sizeof(VerticeSt) * n);
	if (g == NULL) {
		free(lados);
		return NULL;
	}
	g->num_vertices = n;
	g->num_lados = m;
	g->delta = 0;

    qsort(nodos, m, sizeof(u32) * 2 , cmp);
}


void DestruccionDelGrafo(Grafo G)
{
	assert(G != NULL);
	for (size_t i = 0; i < G->num_lados; ++i) {
		free(G->vertices[i].vecinos);
	}
	free(G);
}


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
