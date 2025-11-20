// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef SORTREQUEST_H
#define SORTREQUEST_H

#include "FailedRequest.h"
#include "MyLinkedList.h"

class SortSystem{
    private:
    MyLinkedList* requests;
    public:
        SortSystem(MyLinkedList* requests);
        void mergeSort(int start, int end);
        void merge(int start, int end);
};

#endif