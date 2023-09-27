#include "ip.h"

ip::ip(const string &ip)
{  
    this->texto = ip;
    stringstream ss(ip);
    char delimiter;
    ss >> primerDig >> delimiter >> segundoDig >> delimiter >> terceroDig >> delimiter >> cuartoDig;
}

ip::ip()
{
    this->primerDig = 0;
    this->segundoDig = 0;
    this->terceroDig = 0;
    this->cuartoDig = 0;
}

bool ip::operator>(const ip &direccion)
{
    if (this->primerDig > direccion.primerDig)
    {
        return true;
    }
    else if (this->primerDig < direccion.primerDig)
    {
        return false;
    }
    else if (this->segundoDig > direccion.segundoDig)
    {
        return true;
    }
    else if (this->segundoDig < direccion.segundoDig)
    {
        return false;
    }
    else if (this->terceroDig > direccion.terceroDig)
    {
        return true;
    }
    else if (this->terceroDig < direccion.terceroDig)
    {
        return false;
    }
    else if (this->cuartoDig > direccion.cuartoDig)
    {
        return true;
    }
    else if (this->cuartoDig < direccion.cuartoDig)
    {
        return false;
    }
    return false;
}

bool ip::operator>=(const ip &direccion)
{
    if (this->primerDig > direccion.primerDig)
    {
        return true;
    }
    else if (this->primerDig < direccion.primerDig)
    {
        return false;
    }
    else if (this->segundoDig > direccion.segundoDig)
    {
        return true;
    }
    else if (this->segundoDig < direccion.segundoDig)
    {
        return false;
    }
    else if (this->terceroDig > direccion.terceroDig)
    {
        return true;
    }
    else if (this->terceroDig < direccion.terceroDig)
    {
        return false;
    }
    else if (this->cuartoDig > direccion.cuartoDig)
    {
        return true;
    }
    else if (this->cuartoDig < direccion.cuartoDig)
    {
        return false;
    }
    return true; 
}

bool ip::operator<(const ip &direccion)
{
    if (this->primerDig < direccion.primerDig)
    {
        return true;
    }
    else if (this->primerDig > direccion.primerDig)
    {
        return false;
    }
    else if (this->segundoDig < direccion.segundoDig)
    {
        return true;
    }
    else if (this->segundoDig > direccion.segundoDig)
    {
        return false;
    }
    else if (this->terceroDig < direccion.terceroDig)
    {
        return true;
    }
    else if (this->terceroDig > direccion.terceroDig)
    {
        return false;
    }
    else if (this->cuartoDig < direccion.cuartoDig)
    {
        return true;
    }
    else if (this->cuartoDig > direccion.cuartoDig)
    {
        return false;
    }
    return false; 
}

bool ip::operator<=(const ip &direccion)
{
    if (this->primerDig < direccion.primerDig)
    {
        return true;
    }
    else if (this->primerDig > direccion.primerDig)
    {
        return false;
    }
    else if (this->segundoDig < direccion.segundoDig)
    {
        return true;
    }
    else if (this->segundoDig > direccion.segundoDig)
    {
        return false;
    }
    else if (this->terceroDig < direccion.terceroDig)
    {
        return true;
    }
    else if (this->terceroDig > direccion.terceroDig)
    {
        return false;
    }
    else if (this->cuartoDig < direccion.cuartoDig)
    {
        return true;
    }
    else if (this->cuartoDig > direccion.cuartoDig)
    {
        return false;
    }
    return true; 
}

bool ip::operator==(const ip &direccion)
{
    if (this->primerDig == direccion.primerDig && this->segundoDig == direccion.segundoDig && this->terceroDig == direccion.terceroDig && this->cuartoDig == direccion.cuartoDig)
    {
        return true;
    }
    return false; 
}

void ip::setPrimerDig(const int &primerDig)
{
    this->primerDig = primerDig;
}

void ip::setSegundoDig(const int &segundoDig)
{
    this->segundoDig = segundoDig;
}

void ip::setTercerDig(const int &terceroDig)
{
    this->terceroDig = terceroDig;
}

void ip::setCuartoDig(const int &cuartoDig)
{
    this->cuartoDig = cuartoDig;
}

string ip::getIp()
{
    return texto;
}

int ip::getPrimerDig ()
{
    return primerDig;
}

int ip::getSegundoDig ()
{
    return segundoDig;
}

int ip::getTercerDig ()
{
    return terceroDig;
}

int ip::getCuartoDig ()
{
    return cuartoDig;
}