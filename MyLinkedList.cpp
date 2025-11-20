// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "MyLinkedList.h"
#include <stdexcept>

using namespace std;

//Complejidad: O(1)
MyLinkedList::MyLinkedList(){
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}
//Complejidad: O(1)
MyLinkedList::MyLinkedList(int len):lens(len){
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
//Complejidad: O(1)
int MyLinkedList::length(){
    return this->size;
}
//Complejidad: O(1)
int MyLinkedList::len(){
    return this->lens;
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
string MyLinkedList::getAt(string ipKey){
    MyNodoLL* current = this->head;

    while (current != nullptr){
        if(current->ipKey == ipKey){
            return current->ipData;
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
//Complejidad: O(1)
void MyLinkedList::insertLast(string ip, int accessNumber){
    if (this->size == 0){
        head = new MyNodoLL(ip, accessNumber);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(ip, accessNumber);
        this->tail->next = newNode;
        this->tail = newNode;
    }
    this->size++;
}

//Complejidad: O(1)
void MyLinkedList::insertLast(string data, string key){
    if (this->size == 0){
        head = new MyNodoLL(key, data);
        tail = head;
    }
    else{
        MyNodoLL* newNode = new MyNodoLL(key, data);
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
    MyNodoLL* actualNode = head;
    for (int i = 0; i < pos; i++){
        actualNode = actualNode->next;
    }
    return actualNode->ipKey;
}
//Complejidad: Peor de los casos: O(n), mejor de los casos: O(1)
void MyLinkedList::removeAt(string ipKey){
    if (this->size == 0){
        throw invalid_argument("La lista esta vacia");
    }
    else{
        MyNodoLL* current = head;
        MyNodoLL* nextNode;
        int pos = 0;

        while(current != nullptr){
            if (current->next != nullptr && current->next->ipKey == ipKey){
                if (current->next->next == nullptr){
                    delete tail;
                    tail = current;
                    tail->next = nullptr;
                }
                else{
                    nextNode = current->next;
                    current->next = current->next->next;
                    delete nextNode;
                }
                this->size--;
                if (this->size == 1){
                    tail = head;
                }
                else if(this->size == 0){
                    tail = nullptr;
                    head = nullptr;
                }
                return;
            }
            else if (current->ipKey == ipKey){
                MyNodoLL* temp = head;
                nextNode = head->next;
                delete temp;
                head = nextNode;
                this->size--;
                if (this->size == 1){
                    tail = head;
                }
                if (this->size == 0){
                    tail = nullptr;
                    head = nullptr;
                }
                return;
            }
            current = current->next;
            pos++;
        }
        throw invalid_argument("La llave " + ipKey + " no existe");
    }
}