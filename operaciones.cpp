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

/**
 * Iprime los valores del nodo y el videojuego
 * @param nodo = el apuntador del nodo a imprimir
 */
void imprimirNodo(Nodo * nodo){
    cout << "--- Nodo con ID " << nodo->id << " ---" << endl;
    cout << "Titulo: " << nodo->vg.titulo << endl;
    cout << "Genero: " << nodo->vg.genero << endl;
    cout << "Clasificacion: " << nodo->vg.clasificacion << endl;
    cout << "---------------------" << endl;
}

/**
 * muestra todos los nodos de la lista y sus caracteristicas
 * @param nav = el apuntador de la lista
 */
void mostrarLista(Nodo * nav){
    if(nav == nullptr)
        cout << "Lista vacia :O" << endl;

    while(nav != nullptr){
        imprimirNodo(nav);
        nav = nav->sig;
    }
}

/**
 * Busca en la lista el nodo dado por un id
 * @param nav = apuntador de la lista donde se busca
 * @param id = identificador del nodo a buscar
 * @return
 */
Nodo * buscarNodo(Nodo * nav,int id){
    while(nav != nullptr){
        if(nav->id == id)
            return nav;
        nav = nav->sig;
    }
    return nullptr;
}

/**
 * Asgina el valor de genero del videojuego del nodo
 * @param nodo = nodo a editar
 * @param genero = nuevo genero
 */
void setGenero(Nodo * nodo,string genero){
    nodo->vg.genero = move(genero);
}

/**
 * Asigna el valor de titulo del videojuego del nodo
 * @param nodo = nodo a editar
 * @param titulo = nuevo titulo
 */
void setTitulo(Nodo * nodo,string titulo){
    nodo->vg.titulo = move(titulo);
}

/**
 * Asigna el valor de clasificacion del videojuego del nodo
 * @param nodo = nodo a editar
 * @param clasificacion = nueva clasificacion
 */
void setClasificacion(Nodo * nodo,string clasificacion){
    nodo->vg.clasificacion = move(clasificacion);
}

/**
 * Borra el nodo de una lista dado por su id
 * @param lista = lista donde se encuentra el nodo
 * @param id = identificador del nodo a borrar
 * @return
 */
bool borrarNodo(Nodo ** lista,int id){
    // si no tiene elementos
    if(*lista == nullptr)
        return false;
    Nodo * nav = *lista;
    // si tiene mas elementos buscamos el nodo
    while(nav != nullptr && nav->id != id){
        nav = nav->sig;
    }
    // no se econtro el nodo
    if(nav == nullptr)
        return false;
    // en el caso de sea el primer nodo o el unico nodo de la lista
    if((*lista)->id == id){
        *lista = nav->sig;
        /*if(*lista == nullptr) TODO este codigo provoca una violacion de segmento en memoria
            (*lista)->ant = nullptr;*/
    } else {
        // en el caso de sea otro nodo
        Nodo * aux = nav->ant;
        aux->sig = nav->sig;
        if(aux->sig != nullptr){
            aux->sig->ant = aux;
        }
    }
    // elimina la memoria de un apuntador (su valor)
    delete nav;
    return true;
}

/**
 * Borra todos los elementos de la lista
 * @param lista = apuntador de lista borra por completo
 */
void borrarLista(Nodo ** lista){
    if(*lista != nullptr){
        borrarNodo(lista,(*lista)->id);
        borrarLista(lista);
    }
}

/**
 * Pone los elementos de una segunda lista en la primera considerando los ids
 * @param lista = lista donde se van a poner los elementos
 * @param nav = lista donde extraen los elementos
 */
void unirListas(Nodo ** lista, Nodo * nav){
    // recorremos la segunda lista y lo agregamos a la primera
    while(nav != nullptr){
        Videojuego vg = nav->vg;
        Nodo * nodoCreado = crearNodo(nav->id,vg.genero,vg.titulo,vg.clasificacion);
        if(!insertarNodo(lista,nodoCreado)){
            cout << "No fue posible insertar el nodo con id " << nav->id << endl;
        }
        nav = nav->sig;
    }
}