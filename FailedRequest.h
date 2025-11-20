// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "string"

#ifndef FAILEDREQUEST_H
#define FAILEDREQUEST_H

using namespace std;

class FailedRequest{
    private:
        double totalDays;
        string ip, reason, date;
    public:
        FailedRequest(string month, int days, string time, string ip, string reason);
        double getDay();
        string getTime();
        string getMonth();
        string getIp();
        string getReason();
        string getDate();
        int monthConvertor(string month);
        double getTotalDays();
};
#endif
