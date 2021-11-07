// definimos las funciones declaradas
#include <utility>

#include "header.h"

/**
 * Prepara un nuevo para ser insertado en una lista
 * @param id = indetificador unico del nodo
 * @param genero = a que genero pertecene el videojuego
 * @param titulo = titulo del videojuego
 * @param clasificacion = en que clasificacion se encuentra el juego
 * @return
 */
Nodo * crearNodo(int id,string genero,string titulo,string clasificacion){
    Nodo * nuevoNodo = new Nodo;
    nuevoNodo->id = id;
    /* NOTA, std::move es un contructor de lenguaje, el cual los argumentos pasados por valor, su valor es asignado directamente
     * a la variable, de esta forma, el pasado por valor se asigna directamente la variable y no se vuelve a copiar, por lo que
     * la variable anterior sera eliminada por el compilador*/
    nuevoNodo->vg.genero = std::move(genero);
    nuevoNodo->vg.titulo = std::move(titulo);
    nuevoNodo->vg.clasificacion = std::move(clasificacion);
    /*en la documentacion de c++ se indica que el compilador tiene un valor nativo para los null de los punteros
     * denominado nullptr */
    nuevoNodo->sig = nullptr;
    nuevoNodo->ant = nullptr;
    return nuevoNodo;
}

/**
 * insertar una nodo en la lista
 * @param lista = apuntador del apuntador de la lista a insertar
 * @param nuevoNodo = el apuntador del nuevoNodo a insertar
 * @return
 */
bool insertarNodo(Nodo ** lista,Nodo * nuevoNodo){
    if(*lista == nullptr){
        // la lista vacia, por lo tanto la lista es igual al primer nodo
        *lista = nuevoNodo;
        return true;
    }
    // verficamos si tiene que insertar al princion (un ID menor al primer nodo en la lista)
    if(nuevoNodo->id <= (*lista)->id){
        // ahora vericamos que el ID no sea el mismo
        if(nuevoNodo->id < (*lista)->id){
            // el nuevo nodo apunta a la cabecera
            nuevoNodo->sig = *lista;
            // la cabecera al nuevo nodo
            (*lista)->ant = nuevoNodo;
            // el apuntador de la cabecera apunta al nuevo nodo, ya que hizo el doble enlaze
            *lista = nuevoNodo;
            return true;
        } else {
            return false;
        }
    }
    // en el caso de que sea mayor tenemos que recorrer la lista en el penultimo nodo para su insercion
    // para insertar al final o en medio de la lista
    Nodo * nav = *lista;

    // mienstras el sig nodo no sea null y si el id del nuevo es mayor al siguiente
    // entonces lo recorremos una pocision, ya que es mayor
    while(nav->sig != nullptr && nuevoNodo->id > nav->sig->id){
        // verificamos que exista un ID repetido, si existe un ID repito, se acaba
        if(nav->sig->id == nuevoNodo->id){
            return false;
        }
        nav = nav->sig;
    }
    // por ultimo hacemos los enlaces
    // el nuevo nodo apunta al siguiente del nodo de en medio o el ultimo
    nuevoNodo->sig = nav->sig;
    // el nuevo nodo su anterior apunta al nodo que esta en medio al final,
    // de esta forma estamos indicanod que el nuevo nodo tenga su doble enlace
    // al nodo nav, que ahora es al anterior y el su sig , que ahora es el sig del
    // nodo nodo
    nuevoNodo->ant = nav;
    // ahora el nuevo su sig apunta al nuevo nodo, con los enlaces correctos
    nav->sig  = nuevoNodo;
    return true;
}

/**
 * retorna la cantidad de nodos en una lista
 * @param nav = el apuntador de la lista
 * @return
 */
int cantidad(Nodo * nav){
    int counter = 0;
    while(nav != nullptr){
        counter++;
        nav = nav->sig;
    }
    return counter;
}