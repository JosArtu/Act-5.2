// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "FailedRequest.h"

// Referencias: https://www.geeksforgeeks.org/cpp/substring-in-cpp/ Uso de substr y stoi
// Referencias: https://www.geeksforgeeks.org/cpp/stdstringerase-in-cpp/ Uso de erase
// Referencias: https://www.geeksforgeeks.org/cpp/std-find-in-cpp/ Uso de find
// Complejidad O(1)
FailedRequest::FailedRequest(string month, int days, string time, string ip, string reason){
    this->ip = ip;
    this->reason = reason;
    this->date = to_string(days) + " " + month + " " + time;
    int pos;
    string timeCopy = time;

    pos = timeCopy.find(":");
    double hours = stoi(timeCopy.substr(0, pos));
    timeCopy.erase(0,pos+1);

    pos = timeCopy.find(":");
    double minutes = stoi(timeCopy.substr(0, pos));
    timeCopy.erase(0,pos+1);

    pos = timeCopy.find(":");
    double seconds = stoi(timeCopy.substr(0, pos));
    timeCopy.erase(0,pos+1);

    this->totalDays = 0;
    this->totalDays += monthConvertor(month);
    this->totalDays += double(days);
    this->totalDays += hours/24;
    this->totalDays += (minutes/60)/24;
    this->totalDays += ((seconds/60)/60)/24;

    pos = this->ip.find(":");
    this->ip.erase(pos);
}
//Complejidad O(1)
string FailedRequest::getIp(){
    return this->ip;
}
//Complejidad O(1)
string FailedRequest::getReason(){
    return this->reason;
}

//Complejidad O(1)
string FailedRequest::getDate(){
    return this->date;
}

//Complejidad O(1)
int FailedRequest::monthConvertor(string month){
    if (month == "Jun")
    {
        return 6*30;
    }
    else if (month == "Jul"){
        return 7*30;
    }
    else if (month == "Aug"){
        return 8*30;
    }
    else if (month == "Sep"){
        return 9*30;
    }
    else if (month == "Oct"){
        return 10*30;
    }
    return 0;
}
//Complejidad O(1)
double FailedRequest::getTotalDays(){
    return this->totalDays;
}
