#ifndef LDE_HEADER_H
#define LDE_HEADER_H
#endif //LDE_HEADER_H
#include <iostream>
#include<stdlib.h>
#include<time.h>
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