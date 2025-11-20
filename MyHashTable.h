//José Arturo Mitre García
//A00228334
#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "MyLinkedList.h"
#include "FailedRequest.h"
#include "SortSystem.h" // <----------------- Cambiar esto en caso de que se utilice otra lista enlazada
//En caso de utilizar tu lista enlazada recuerda también enviar el archivo para poder compilar y ejecutar el programa

using namespace std;

class MyHashTable{
    public://Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser private
       MyLinkedList* tabla;
       int size; //Cantidad de valores que hay almacenados en la tabla
       int sizeA; //Cantidad del arreglo
       void rehashing(); //Crece el arreglo al doble del tamaño del arreglo actual + 1
       int getPos(string ipKey);

       MyHashTable();  //Tamaño inicial 11
       ~MyHashTable();
       bool isEmpty();
       void put(FailedRequest* request);
       void get(string ipKey);
       void sortLists();
};
#endif
