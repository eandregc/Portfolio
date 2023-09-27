#ifndef CLASS_IP_H
#define CLASS_IP_H

#include <iostream>
#include <sstream>
using namespace std;

class ip
{
private:
    string texto;
    int primerDig;
    int segundoDig;
    int terceroDig;
    int cuartoDig;
public:
    ip(const string &ip);
    ip();
    bool operator> (const ip &direccion);
    bool operator>= (const ip &direccion);
    bool operator< (const ip &direccion);
    bool operator<= (const ip &direccion);
    bool operator== (const ip &direccion);
    void setPrimerDig(const int &primerDig);
    void setSegundoDig(const int &segundoDig);
    void setTercerDig(const int &terceroDig);
    void setCuartoDig(const int &cuartoDig);
    string getIp();
    int getPrimerDig ();
    int getSegundoDig ();
    int getTercerDig ();
    int getCuartoDig ();
};

#endif 