// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "SearchSystem.h"
#include <iostream>

SearchSystem::SearchSystem(){
    tabla = new MyHashTable();
}
//Complejidad: O(1)
SearchSystem::~SearchSystem(){
    delete tabla;
}
void SearchSystem::insertRequest(FailedRequest* request){
    this->tabla->put(request);
}
//Complejidad: O(n, N), donde la n es la cantidad de top IPs que se piden y  la N seria los nodos del arbol, cuando el usuario pone 
// n > N, solo va recorrer hasta N y no llenara la lista, solo pondra todos los nodos del arbol en la lista.
void SearchSystem::searchRequest(string ipKey){
    this->tabla->get(ipKey);
}

void SearchSystem::sortRequests(){
    this->tabla->sortLists();
}