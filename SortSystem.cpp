// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "SortSystem.h"

//Complejidad O(n log n)
void SortSystem::sortList(MyLinkedList* requests){
    this->requests = requests;
    int end = requests->length();
    mergeSort(0, end - 1);
}

//Complejidad O(n log n)
void SortSystem::mergeSort(int start, int end){
    if(start<end){
        int central = (start+end)/2;
        mergeSort(start,central);
        mergeSort(central+1,end); 
        merge(start, end);
        
    }
}
//Complejidad O(n)
void SortSystem::merge(int start, int end){
    int central = (start + end) / 2;
    int i = start;
    int j = central + 1;
    MyNodoLL* iNode = requests->getAtNode(i);
    MyNodoLL* jNode = requests->getAtNode(j);
    MyLinkedList arreglo;

    while(i <= central && j <= end){
        if(iNode->request->getTotalDays() >= jNode->request->getTotalDays()){
            arreglo.insertLast(iNode->request);
            iNode = iNode->next;
            i++;
        }else{
            arreglo.insertLast(jNode->request);
            jNode = jNode->next;
            j++;
        }
    }

    while(i <= central){
        arreglo.insertLast(iNode->request);
        iNode = iNode->next;
        i++;
    }

    while(j <= end){
        arreglo.insertLast(jNode->request);
        jNode = jNode->next;
        j++;
    }
    MyNodoLL* bitacoraNode = requests->getAtNode(start);
    MyNodoLL* arregloNode = arreglo.getAtNode(0);
    for(int k=0; k < arreglo.length(); k++){
        bitacoraNode->request = arregloNode->request;
        bitacoraNode = bitacoraNode->next;
        arregloNode = arregloNode->next;
    }
}