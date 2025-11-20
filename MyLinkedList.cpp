// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "MyLinkedList.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//Complejidad: O(1)
MyLinkedList::MyLinkedList(){
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}
//Complejidad: O(n)
MyLinkedList::~MyLinkedList(){
    MyNodoLL* actualNode = head;
    MyNodoLL* nextNode;
    for (int i = 0; i < this->size; i++)
    {
        nextNode = actualNode->next;
        delete actualNode;
        actualNode = nextNode;
    }
}
//Complejidad: O(n)
void MyLinkedList::flushRequests(){
    MyNodoLL* actualNode = head;
    MyNodoLL* nextNode;
    for (int i = 0; i < this->size; i++)
    {
        nextNode = actualNode->next;
        delete actualNode->request;
        actualNode = nextNode;
    }
}
//Complejidad: O(1)
int MyLinkedList::length(){
    return this->size;
}
//Complejidad: O(n)
MyNodoLL* MyLinkedList::getAtNode(int pos){
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode;
}
//Complejidad: O(n)
FailedRequest* MyLinkedList::getAt(int pos){
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->request;
}
//Complejidad: O(n)
void MyLinkedList::getAt(string ipKey){
    MyNodoLL* current = this->head;
    bool keyExists = false;

    while (current != nullptr){
        if(current->request->getIp() == ipKey){
            cout << current->request->getDate() << "\n";
            keyExists = true;
        }
        current = current->next;
    }
    if (!keyExists)
    {
        throw invalid_argument("La llave " + ipKey + " no existe.");
    }
}
//Complejidad: O(1)
void MyLinkedList::insertLast(double days, string time, string ip, string reason, string month, string date){
    if (this->size == 0){
        head = new MyNodoLL(days, time, ip, reason, month, date);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(days, time, ip, reason, month, date);
        this->tail->next = newNode;
        this->tail = newNode;
        this->tail->next = nullptr;
    }
    this->size++;
}
//Complejidad: O(1)
void MyLinkedList::insertLast(FailedRequest* request){
    if (this->size == 0){
        head = new MyNodoLL(request);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(request);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

//Complejidad: O(n)
string MyLinkedList::getKey(int pos){
    if (this->size == 0){
        throw invalid_argument("La lista esta vacia");
    }
    if (this->size <= pos || pos < 0){
        throw invalid_argument("Posicion invalida/fuera de rango");
    }
    MyNodoLL* actualNode = this->head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->request->getIp();
}
//Complejidad: O(n)
string MyLinkedList::getDate(int pos){
    if (this->size == 0){
        throw invalid_argument("La lista esta vacia");
    }
    if (this->size <= pos || pos < 0){
        throw invalid_argument("Posicion invalida/fuera de rango");
    }
    MyNodoLL* actualNode = this->head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->request->getDate();
}