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

// segundo sample de datos para la union de listas
Videojuego vgDos[3] = {
        {
            "RPG",
            "Pokemon Esmeralda",
            "P8"
        },
        {
            "Puzzles",
            "Tomb Raider",
            "P14"
        },
        {
            "Estrategia",
            "Age of Emprires IV",
            "P13"
        }
};


int main() {
    // variables globales
    char res;
    int id;
    // iniciamos la lista
    Nodo * lista = nullptr;
    // llenamos la lista con los datos de prueba
    // iniciamos una semilla para el random
    srand(time(nullptr));
    for(Videojuego &vg : videojuegos){
        id = rand() % 51;
        id = id == 0 ? 1 : id;
        Nodo * nodoCreado = crearNodo(id,vg.genero,vg.titulo,vg.clasificacion);
        if(!insertarNodo(&lista,nodoCreado)){
            cout << "No fue posible insertar el nodo con id " << id << endl;
        }
    }
    cout << "La cantidad de nodos insertados es: " << cantidad(lista) << endl;
    cout << "La lista esta compuesta por: " << endl;
    mostrarLista(lista);
    cout << "¿Desea buscar un nodo?" << endl;
    cout << "s/n: "; cin.get(res);
    if(res == 's'){
        cout << "id del nodo: "; cin >> id;
        Nodo * nodoBuscado = buscarNodo(lista,id);
        if(nodoBuscado != nullptr) {
            cout << "--- Nodo encontrado :D ---" << endl;
            imprimirNodo(nodoBuscado);
            // preguntamos si desea editar el nodo;
            res = '\0';
            cout << "¿Desea editar el nodo?" << endl;
            cout << "s/n: "; cin.get(res);
            res = getchar();
            if(res == 's'){
                string titulo,genero,clasificacion;
                cout << "--- editando nodo  ---" << endl;
                cout << "Titulo: "; cin >> titulo;
                cout << "Genero: "; cin >> genero;
                cout << "Clasificacion: "; cin >> clasificacion;
                setTitulo(nodoBuscado,titulo);
                setGenero(nodoBuscado,genero);
                setClasificacion(nodoBuscado,clasificacion);
                cout << "--- imprimiendo nodo editado ---" << endl;
                imprimirNodo(nodoBuscado);
            }
        } else {
            cout << "-- no encotrando :( -- " << endl;
        }
    }

    // preguntamos si quieren mezclar una segunda lista
    // insertamos la segunda lista
    cout << "--- Mostrando segunda lista de juegos --- " << endl;
    Nodo * segundaLista = nullptr;
    for(Videojuego &vg : vgDos){
        id = rand() % 51;
        id = id == 0 ? 1 : id;
        Nodo * nodoCreado = crearNodo(id,vg.genero,vg.titulo,vg.clasificacion);
        if(!insertarNodo(&segundaLista,nodoCreado)){
            cout << "No fue posible insertar el nodo con id " << id << endl;
        }
    }
    // presentamos la segunda lista
    mostrarLista(segundaLista);
    cout << "¿Desea mezclar las listas?" << endl;
    res = '\0';
    cout << "s/n: "; cin.get(res);
    res = getchar();
    if(res == 's'){
        cout << "--- mezclando listas ---" << endl;
        unirListas(&lista,segundaLista);
        cout << "--- Mostrando lista mezclada ---" << endl;
        mostrarLista(lista);
        cout << "La lista cuenta actualmente con " << cantidad(lista) << " elementos" << endl;
    }

    res = '\0';
    cout << "¿Deseas eliminar un nodo?" << endl;
    cout << "s/n: "; cin.get(res);
    res = getchar();
    if(res == 's'){
        cout << "id del nodo: "; cin >> id;
        if(!borrarNodo(&lista,id))
            cout << "nodo no borrado con id " << id << endl;
        cout << "*** numero de elemntos en la lista: " << cantidad(lista) << endl;
        cout << "--- mostrando lista ----" << endl;
        mostrarLista(lista);
    }

    // preguntamos si quieren borrar toda la lista
    res = '\0';
    cout << "¿Deseas eliminar toda la lista?" << endl;
    cout << "s/n: "; cin.get(res);
    res = getchar();
    if(res == 's'){
        borrarLista(&lista);
        cout << "--- mostrando lista ----" << endl;
        mostrarLista(lista);
        cout << "*** numero de elemntos en la lista: " << cantidad(lista) << endl;

    }
    return 0;
}
