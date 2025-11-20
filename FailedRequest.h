// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "string"

#ifndef FAILEDREQUEST_H
#define FAILEDREQUEST_H

using namespace std;

class FailedRequest{
    private:
        double days, ipSortValue, totalDays;
        string ip, reason, month, time, date;
    public:
        FailedRequest(string month, double days, string time, string ip, string reason, string date);
        double getDay();
        double getIpSortValue();
        string getTime();
        string getMonth();
        string getIp();
        string getReason();
        string getDate();
        int monthConvertor(string month);
        double getTotalDays();
};
#endif
