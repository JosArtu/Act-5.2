// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "SearchSystem.h"
#include <iostream>
//Complejidad: Mejor de los casos: O(log n), peor de los casos: O(n)
SearchSystem::SearchSystem(MyLinkedList* bitacora): bitacora(bitacora){
    int pos;
    string highDate, lowDate;
    double lowestDateValue, highestDateValue, actualDateValue;
    string currentIp;
    string nextIp;
    MyNodoLL* currentNode = bitacora->getAtNode(0);
    tabla = new MyHashTable();

    lowestDateValue = currentNode->request->getTotalDays();
    highestDateValue = lowestDateValue;
    highDate = currentNode->request->getDate();
    lowDate = highDate;
    while (currentNode != nullptr){
        currentIp = currentNode->request->getIp();
        pos = currentIp.find(":");
        currentIp = currentIp.erase(pos);
        if (currentNode->next != nullptr)
        {
            nextIp = currentNode->next->request->getIp();
            pos = nextIp.find(":");
            nextIp = nextIp.erase(pos);
        }
        else{
            nextIp = "";
        }
        if (currentIp == nextIp && currentNode->next != nullptr){
            actualDateValue = currentNode->next->request->getTotalDays();
            if (actualDateValue > highestDateValue){
                highestDateValue = actualDateValue;
                highDate = currentNode->next->request->getDate();
            }
            else if(actualDateValue < lowestDateValue){
                lowestDateValue = actualDateValue;
                lowDate = currentNode->next->request->getDate();
            }
        }
        else{
            tabla->put(currentIp, highDate + "\n" + lowDate);
            if (currentNode->next != nullptr){
                lowestDateValue = currentNode->next->request->getTotalDays();
                highestDateValue = lowestDateValue;
                highDate = currentNode->next->request->getDate();
                lowDate = highDate;
            }
        }
        currentNode = currentNode->next;
    }
}
//Complejidad: O(1)
SearchSystem::~SearchSystem(){
    delete tabla;
}
//Complejidad: O(n, N), donde la n es la cantidad de top IPs que se piden y  la N seria los nodos del arbol, cuando el usuario pone 
// n > N, solo va recorrer hasta N y no llenara la lista, solo pondra todos los nodos del arbol en la lista.
void SearchSystem::searchRequest(string ipKey){
    string output = tabla->get(ipKey);
    cout << output << endl;
}