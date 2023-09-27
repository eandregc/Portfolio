#include "tiempo.h"

tiempo::tiempo(string hora, string minuto, string segundo)
{
    stringstream ss(hora);
    horaTexto = hora;
    minutoTexto = minuto;
    segundoTexto = segundo;
    ss << hora;
    ss >> this->hora;
    ss.clear();
    ss << minuto;
    ss >> this->minuto;
    ss.clear();
    ss << segundo;
    ss >> this->segundo;
}

tiempo::tiempo()
{
    this->hora = 0;
    this->minuto = 0;
    this->segundo = 0;
}

bool tiempo::operator>(const tiempo &tiempo)
{
    if (this->hora > tiempo.hora)
    {
        return true;
    }
    else if (this->hora < tiempo.hora)
    {
        return false;
    }
    else if (this->minuto > tiempo.minuto)
    {
        return true;
    }
    else if (this->minuto < tiempo.minuto)
    {
        return false;
    }
    else if (this->segundo > tiempo.segundo)
    {
        return true;
    }
    else if (this->segundo < tiempo.segundo)
    {
        return false;
    }
    return false; 
}

bool tiempo::operator>=(const tiempo &tiempo)
{
    if (this->hora > tiempo.hora)
    {
        return true;
    }
    else if (this->hora < tiempo.hora)
    {
        return false;
    }
    else if (this->minuto > tiempo.minuto)
    {
        return true;
    }
    else if (this->minuto < tiempo.minuto)
    {
        return false;
    }
    else if (this->segundo > tiempo.segundo)
    {
        return true;
    }
    else if (this->segundo < tiempo.segundo)
    {
        return false;
    }
    return true; 
}

bool tiempo::operator<(const tiempo &tiempo)
{
    if (this->hora < tiempo.hora)
    {
        return true;
    }
    else if (this->hora > tiempo.hora)
    {
        return false;
    }
    else if (this->minuto < tiempo.minuto)
    {
        return true;
    }
    else if (this->minuto > tiempo.minuto)
    {
        return false;
    }
    else if (this->segundo < tiempo.segundo)
    {
        return true;
    }
    else if (this->segundo > tiempo.segundo)
    {
        return false;
    }
    return false; 
}

bool tiempo::operator<=(const tiempo &tiempo)
{
    if (this->hora < tiempo.hora)
    {
        return true;
    }
    else if (this->hora > tiempo.hora)
    {
        return false;
    }
    else if (this->minuto < tiempo.minuto)
    {
        return true;
    }
    else if (this->minuto > tiempo.minuto)
    {
        return false;
    }
    else if (this->segundo < tiempo.segundo)
    {
        return true;
    }
    else if (this->segundo > tiempo.segundo)
    {
        return false;
    }
    return true; 
}

bool tiempo::operator==(const tiempo &tiempo)
{
    if (this->hora == tiempo.hora && this->minuto == tiempo.minuto && this->segundo == tiempo.segundo)
    {
        return true;
    }
    return false; 
}

void tiempo::setHora(const int &hora)
{
    this->hora = hora;
}

void tiempo::setMinuto(const int &minuto)
{
    this->minuto = minuto;
}

void tiempo::setSegundo(const int &segundo)
{
    this->segundo = segundo;
}

int tiempo::getHora()
{
    return hora;
}

int tiempo::getMinuto()
{
    return minuto;
}

int tiempo::getSegundo()
{
    return segundo;
}

string tiempo::getHoraTexto()
{
    return horaTexto;
}

string tiempo::getMinutoTexto()
{
    return minutoTexto;
}

string tiempo::getSegundoTexto()
{
    return segundoTexto;
}
