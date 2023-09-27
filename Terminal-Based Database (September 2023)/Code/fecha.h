#ifndef CLASS_FECHA_H
#define CLASS_FECHA_H

#include <iostream>
using namespace std;

class fecha
{
private:
    string mes;
    int dia;
    int año;
    int mesNum;
public:
    fecha(const string &, const int &, const int &);
    fecha(const int &, const int &, const int &);
    fecha();
    bool operator> (const fecha &fecha);
    bool operator>= (const fecha &fecha);
    bool operator< (const fecha &fecha);
    bool operator<= (const fecha &fecha);
    bool operator== (const fecha &fecha);
    void setMes (const string &mes);
    void setMesNum (const int &mesNum);
    void setDia (const int &dia);
    void setAño (const int &año);
    string getMes ();
    int getMesNum ();
    int getDia ();
    int getAño ();
};

#endif 