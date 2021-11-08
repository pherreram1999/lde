#ifndef LDE_HEADER_H
#define LDE_HEADER_H
#endif //LDE_HEADER_H
#include <iostream>
// librerias recomendas para entornos GNU/Linux
#include<cstdlib>
#include<ctime>
using namespace std;

typedef struct videojuego {
    string genero;
    string titulo;
    string clasificacion;
} Videojuego;

typedef struct nodo {
    int id;
    Videojuego vg;
    struct nodo * sig;
    struct nodo * ant;
} Nodo;


// declaramos las funciones

Nodo * crearNodo(int,string,string,string);

bool insertarNodo(Nodo ** ,Nodo *);

int cantidad(Nodo *);

void imprimirNodo(Nodo *);

void mostrarLista(Nodo *);

Nodo * buscarNodo(Nodo *,int id);

void setGenero(Nodo*,string);

void setTitulo(Nodo*,string);

void setClasificacion(Nodo*,string);

bool borrarNodo(Nodo **,int);

void borrarLista(Nodo **);

void unirListas(Nodo **,Nodo*);