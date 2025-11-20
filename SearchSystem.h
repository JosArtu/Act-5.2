// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef SEARCHSYSTEM_H
#define SEARCHSYSTEM_H

#include "MyHashTable.h"
#include "MyLinkedList.h"

class SearchSystem{
    private:
        MyHashTable* tabla;
        MyLinkedList* bitacora;
        void printRequests(MyLinkedList* lista);
    public:
        SearchSystem(MyLinkedList* bitacora);
        ~SearchSystem();
        void searchRequest(string ipKey);
};

#endif