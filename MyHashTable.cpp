//José Arturo Mitre García
//A00228334
#include "MyHashTable.h"
#include <iostream>
//Complejidad O(1)
MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=16807;
    this->tabla=new MyLinkedList[this->sizeA];
}
//Complejidad: O(1)
MyHashTable::~MyHashTable(){
    delete[] tabla;
}
//Complejidad(O(1))
int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}
//Complejidad(O(n))
//Profe habia utilizado la tecnica de usar un puntero a un nodo para recorrerlo adentro del rehash y que no estuviera pidiendo
//.getKey y .getAt adentro del ciclo solo current.key, current.data pero me dijo que rompia el paradigma de la programacion
//orientada a objetos y por eso los puse asi
void MyHashTable::rehashing(){
    int oldSizeA = this->sizeA;
    this->sizeA = this->sizeA*2 +1;
    MyLinkedList* oldTabla = this->tabla;
    MyLinkedList* newTabla = new MyLinkedList[this->sizeA];
    string key, data;
    int pos;
    
    for (int i = 0; i < oldSizeA; i++){
        int lenght = oldTabla[i].length();
        for (int j = 0; j < lenght; j++){
            key = oldTabla[i].getKey(j);
            data = oldTabla[i].getAt(key);

            pos = this->getPos(key);

            newTabla[pos].insertLast(data, key);
        }
        
    }
    this->tabla = newTabla;
    delete[] oldTabla;
}
//Complejidad: O(1), O(n) si rehash
void MyHashTable::put(string ipKey, string ipData){
    int pos = this->getPos(ipKey);

    this->tabla[pos].insertLast(ipData, ipKey);
    this->size++;
    if (double(this->size)/double(this->sizeA) > 0.75){
        this->rehashing();
    }
}
//Complejidad: O(1) mejor caso, O(n) peor caso
string MyHashTable::get(string key){
    int pos = this->getPos(key);
    try{
        return this->tabla[pos].getAt(key);
    }
    catch(const std::exception& e){
        cout << e.what() << '\n';
        return "";
    }
}
//Complejidad: O(1), O(n) peor caso
void MyHashTable::remove(string key){
    int pos = this->getPos(key);
    try{
        this->tabla[pos].removeAt(key);
    }
    catch(const std::exception& e){
        cout << e.what() << '\n';
    }
}
//Complejidad: O(1)
bool MyHashTable::isEmpty(){
    return this->size == 0;
}