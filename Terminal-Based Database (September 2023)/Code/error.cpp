#include "error.h"

error::error(const string &nombre, const fecha &f, const tiempo &t, const ip &i)
{
    this->nombre = nombre;
    this->f = f;
    this->t = t;
    this->i = i;
}

error::error()
{
    fecha nullF("0", 0, 0);
    tiempo nullT("00", "00", "00");
    ip nullI("000000000");
    this->nombre = "null";
    this->f = nullF;
    this->t = nullT;
    this->i = nullI;
}

void error::printError()
{
   cout << this->f.getMes() << " " << this->f.getDia() << " " << this->f.getAño() << this->t.getHoraTexto() << ":" << this->t.getMinutoTexto() << ":" << this->t.getSegundoTexto() << " " << this->i.getIp() << this->nombre << endl;
}

string error::getNombre()
{
    return this->nombre;
}

fecha error::getFecha()
{
    return this->f;
}

tiempo error::getTiempo()
{
    return this->t;
}

ip error::getIp()
{
    return this->i;
}