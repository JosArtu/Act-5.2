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
    int accessNumber;

    MyNodoLL(double days, string time, string ip, string reason, string month, string date, MyNodoLL* next){
        this->request = new FailedRequest(month, days, time, ip, reason);
        this->next = next;
    }
    MyNodoLL(double days, string time, string ip, string reason, string month, string date):MyNodoLL(days, time, ip, reason, month, date,  nullptr){};
    MyNodoLL(FailedRequest* request):request(request){
        this->next = nullptr;
    }
};



class MyLinkedList{
    private:
        int size;
        MyNodoLL* head;
        MyNodoLL* tail;
    public:
        MyLinkedList();
        ~MyLinkedList();
        void flushRequests();
        int length();
        MyNodoLL* getAtNode(int pos);
        FailedRequest* getAt(int pos); 
        void insertLast(double days, string time, string ip, string reason, string month, string date);
        void insertLast(FailedRequest* request);
        void getAt(string ipKey);
        string getDate(int pos);
        string getKey(int pos);
};
#endif