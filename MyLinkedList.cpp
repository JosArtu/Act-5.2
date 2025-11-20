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
    for (int i = 0; i < this->size; i++){
        nextNode = actualNode->next;
        if (actualNode->resumenFechas != nullptr){
            actualNode->resumenFechas->flushRequests();
        }
        if (actualNode->request != nullptr){
           delete actualNode->request;
        }
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

    while (current != nullptr){
        if(current->ip == ipKey){
            current = current->resumenFechas->getAtNode(0);
            while (current != nullptr){
                cout << current->request->getDate() << "\n";
                current = current->next;
            }
            return;
        }
        current = current->next;
    }
    throw invalid_argument("La llave " + ipKey + " no existe.");
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
        this->head = new MyNodoLL(request);
        this->tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(request);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

void MyLinkedList::insertLast(string ip, MyLinkedList* ipDates){
    if (this->size == 0){
        this->head = new MyNodoLL(ip);
        this->tail = head;
        this->head->resumenFechas = ipDates;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(ip);
        this->tail->next = newNode;
        this->tail = newNode;
        newNode->resumenFechas = ipDates;
    }
    this->size++;
};

bool MyLinkedList::insertIpLast(FailedRequest* request){
    if (this->size == 0){
        head = new MyNodoLL(request->getIp());
        tail = head;
        tail->resumenFechas = new MyLinkedList();
    }
    else{
        MyNodoLL* current = this->head;
        while (current != nullptr){
            if (current->ip == request->getIp()){
                current->resumenFechas->insertLast(request);
                return false;
            }
            current = current->next;
        }
        MyNodoLL* newNode = new MyNodoLL(request->getIp());
        newNode->resumenFechas = new MyLinkedList();
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
    return true;
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
    return actualNode->ip;
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
//Complejidad: O(n)
MyLinkedList* MyLinkedList::getIpDatesInfo(string ipKey){
    MyNodoLL* current = this->head;

    while (current != nullptr){
        if(current->ip == ipKey){
            return current->resumenFechas;
        }
        current = current->next;
    }
    throw invalid_argument("La llave " + ipKey + " no existe.");
}

void MyLinkedList::sortIpDates(){
    MyNodoLL* current = this->head;
    SortSystem sort;

    while (current != nullptr){
        sort.sortList(current->resumenFechas);
        current = current->next;
    }
    
}