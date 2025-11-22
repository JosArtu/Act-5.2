// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "LoginSystem.h"

// Referencias: https://www.youtube.com/watch?v=Re417iwYM84 Lectura de archivos
// Referencias: https://www.geeksforgeeks.org/cpp/stdstringerase-in-cpp/ Uso de erase
// Referencias: https://www.youtube.com/watch?v=Rfe2Jb2JP-Y escritura de archivos
// Referencias: https://www.geeksforgeeks.org/cpp/getline-string-c/ Getline para tomar todo el input con espacios
// Complejidad: O(n log n)
LoginSystem::LoginSystem(){
    int days;
    string time, ip, reason, month;
    FileLocation = "bitacora3.txt";
    ifstream rawFile(FileLocation);
    this->searchRequests = new SearchSystem();

    while (!rawFile.eof()){
        rawFile >> month;
        rawFile >> days;
        rawFile >> time;
        rawFile >> ip; 

        getline(rawFile, reason);
        reason.erase(0, 1);

        this->searchRequests->insertRequest(new FailedRequest(month, days, time, ip, reason));
    }

    this->searchRequests->sortRequests();
}
//Complejidad O(n)
LoginSystem::~LoginSystem(){
    delete searchRequests;
}
//Complejidad: O(1) Mejor caso, O(n) peor caso
void LoginSystem::searchIpData(string ipKey){
    this->searchRequests->searchRequest(ipKey);
}
