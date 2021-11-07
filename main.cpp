#include "header.h"

/* vamos crear un sample data para faciltiar las pruebas*/

Videojuego videojuegos[5] = {
        {
            "Shooter",
            "Doom",
            "P16"
        },
        {
            "Sandbox",
            "Grand Theft Auto",
            "P18"
        },
        {
            "Hackslash",
            "Bayonetta",
            "P18"
        },
        {
            "Carreras",
            "Need For Speed",
            "P13"
        },
        {
            "Arcade",
            "Metal Slug X",
            "P8"
        }
};


int main() {
    // iniciamos la lista
    Nodo * lista = nullptr;
    // llenamos la lista con los datos de prueba
    // iniciamos una semilla para el random
    srand(time(nullptr));
    for(Videojuego &vg : videojuegos){
        int id = rand() % 51;
        id = id == 0 ? 1 : id;
        Nodo * nodoCreado = crearNodo(id,vg.genero,vg.titulo,vg.clasificacion);
        if(!insertarNodo(&lista,nodoCreado)){
            cout << "No fue posible insertar el nodo con id " << id << endl;
        }
    }
    return 0;
}
