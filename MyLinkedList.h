// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "FailedRequest.h"
#include "SortSystem.h"
using namespace std;


class MyLinkedList;

struct MyNodoLL{
    MyLinkedList* resumenFechas = nullptr;
    MyNodoLL* next;
    FailedRequest* request = nullptr;
    string ip;

    MyNodoLL(double days, string time, string ip, string reason, string month, string date, MyNodoLL* next){
        this->request = new FailedRequest(month, days, time, ip, reason);
        this->next = next;
    }
    MyNodoLL(double days, string time, string ip, string reason, string month, string date):MyNodoLL(days, time, ip, reason, month, date,  nullptr){};
    MyNodoLL(FailedRequest* request):request(request){
        this->next = nullptr;
    }
    MyNodoLL(string ip, MyNodoLL* next):ip(ip),next(next){}
    MyNodoLL(string ip):MyNodoLL(ip,nullptr){}

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
        void insertLast(string ip, MyLinkedList* ipDates);
        bool insertIpLast(FailedRequest* request);
        void getAt(string ipKey);
        string getDate(int pos);
        string getKey(int pos);
        MyLinkedList* getIpDatesInfo(string ipKey);
        void sortIpDates();
};
#endif