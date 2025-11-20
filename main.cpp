// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include <iostream>
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"
#include "LoginSystem.h"
#include "LoginSystem.cpp"
#include "FailedRequest.h"
#include "FailedRequest.cpp"
#include "SortSystem.h"
#include "SortSystem.cpp"
#include "SearchSystem.h"
#include "SearchSystem.cpp"
#include "MyHashTable.h"
#include "MyHashTable.cpp"

using namespace std;

int main(){
    LoginSystem system1;
    string ip;
    int opt;
    do{
        cout << "Ingrese IP: ";
        cin >> ip;
        system1.searchIpData(ip);
        cout << "¿Desea consultar otra IP? (1/0): ";
        cin >> opt;
    } while (opt == 1);
    

    return 0;
}