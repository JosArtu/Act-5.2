// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "FailedRequest.h"
using namespace std;

struct MyNodoLL{
    MyNodoLL* next;
    FailedRequest* request;
    string ipKey;
    string ipData, ip;
    int accessNumber;

    MyNodoLL(double days, string time, string ip, string reason, string month, string date, MyNodoLL* next){
        this->request = new FailedRequest(month, days, time, ip, reason, date);
        this->next = next;
    }
    MyNodoLL(double days, string time, string ip, string reason, string month, string date):MyNodoLL(days, time, ip, reason, month, date,  nullptr){};
    MyNodoLL(FailedRequest* request):request(request){
        next = nullptr;
    }
    MyNodoLL(string ip, int accessNumber):ipKey(ipKey), accessNumber(accessNumber){
        next = nullptr;
    }
    MyNodoLL(string ipKey, string ipData, MyNodoLL* next): ipKey(ipKey), ipData(ipData), next(next){}
    MyNodoLL(string ipKey, string ipData): MyNodoLL(ipKey, ipData, nullptr){}
};



class MyLinkedList{
    private:
        int size, lens;
        MyNodoLL* head;
        MyNodoLL* tail;
    public:
        MyLinkedList();
        MyLinkedList(int len);
        ~MyLinkedList();
        int length();
        int len();
        MyNodoLL* getAtNode(int pos);
        FailedRequest* getAt(int pos); 
        void insertLast(double days, string time, string ip, string reason, string month, string date);
        void insertLast(FailedRequest* request);
        void insertLast(string ip, int accessNumber);
        void insertLast(string ip, string ipData);
        string getAt(string key);
        string getKey(int pos);
        void removeAt(string key);
};
#endif