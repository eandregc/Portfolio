#ifndef CLASS_ERROR_H
#define CLASS_ERROR_H

#include <iostream>
#include "fecha.h"
#include "tiempo.h"
#include "ip.h"
using namespace std;

class error
{
private:
    string nombre;
    fecha f;
    tiempo t;
    ip i;

public:
    error(const string &nombre, const fecha &f, const tiempo &t, const ip &i);
    error();
    void printError();
    string getNombre();
    fecha getFecha();
    tiempo getTiempo();
    ip getIp();
};

#endif 
