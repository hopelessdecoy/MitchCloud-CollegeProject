#ifndef SECURITY_H
#define SECURITY_H

#include "order.h"

class security
{
    public:
        security();
        ~security();

        string loginName();
        string loginPass();
        void writeToLog(string log);
        void readLog();
        int checkIN(int selection);
        int secCheck(string name, string passw);

    private:
        string usrName[4]= {"ICE", "FLOYD", "METALLICA","ZEPPELIN"};
        string pass[4]= {"CUBE", "THINICE", "UNDERICE","ICEANDSNOW"};
};

#endif // SECURITY_H
