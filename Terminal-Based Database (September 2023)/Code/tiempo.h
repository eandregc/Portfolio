#ifndef CLASS_TIEMPO_H
#define CLASS_TIEMPO_H

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class tiempo
{
private:
    string horaTexto;
    string minutoTexto;
    string segundoTexto;
    int hora;
    int minuto;
    int segundo;
public:
    tiempo(string hora, string minuto, string segundo);
    tiempo();
    bool operator> (const tiempo &tiempo);
    bool operator>= (const tiempo &tiempo);
    bool operator< (const tiempo &tiempo);
    bool operator<= (const tiempo &tiempo);
    bool operator== (const tiempo &tiempo);
    void setHora (const int &hora);
    void setMinuto (const int &minuto);
    void setSegundo (const int &segundo);
    int getHora ();
    int getMinuto ();
    int getSegundo ();
    string getHoraTexto();
    string getMinutoTexto();
    string getSegundoTexto();
};

#endif 