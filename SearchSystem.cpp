// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "SearchSystem.h"
#include <iostream>
//Complejidad: O(1)
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
//Complejidad: O(1) Mejor caso, O(n) peor caso
void SearchSystem::searchRequest(string ipKey){
    this->tabla->get(ipKey);
}
//Complejidad: O(1) mejor caso, O(n) peor caso
void SearchSystem::sortRequests(){
    this->tabla->sortLists();
}