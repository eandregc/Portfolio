#include "fecha.h"

fecha::fecha(const string &mes, const int &dia, const int &año)
{
    this->mes = mes;
    this->dia = dia;
    this->año = año;
    if (mes == "Jan")
    {
        mesNum = 1;
    }
    else if (mes == "Feb")
    {
        mesNum = 2;
    }
    else if (mes == "Mar")
    {
        mesNum = 3;
    }
    else if (mes == "Apr")
    {
        mesNum = 4;
    }
    else if (mes == "May")
    {
        mesNum = 5;
    }
    else if (mes == "Jun")
    {
        mesNum = 6;
    }
    else if (mes == "Jul")
    {
        mesNum = 7;
    }
    else if (mes == "Aug")
    {
        mesNum = 8;
    }
    else if (mes == "Sep")
    {
        mesNum = 9;
    }
    else if (mes == "Oct")
    {
        mesNum = 10;
    }
    else if (mes == "Nov")
    {
        mesNum = 11;
    }
    else if (mes == "Dec")
    {
        mesNum = 12;
    }
    else
    {
        mesNum = 0;
    }
}

fecha::fecha(const int &mes, const int &dia, const int &año)
{
    this->mesNum = mes;
    this->dia = dia;
    this->año = año;
    if (mes == 1)
    {
        this->mes = "Jan";
    }
    else if (mes == 2)
    {
        this->mes = "Feb";
    }
    else if (mes == 3)
    {
        this->mes = "Mar";
    }
    else if (mes == 4)
    {
        this->mes = "Apr";
    }
    else if (mes == 5)
    {
        this->mes = "May";
    }
    else if (mes == 6)
    {
        this->mes = "Jun";
    }
    else if (mes == 7)
    {
        this->mes = "Jul";
    }
    else if (mes == 8)
    {
        this->mes = "Aug";
    }
    else if (mes == 9)
    {
        this->mes = "Sep";
    }
    else if (mes == 10)
    {
        this->mes = "Oct";
    }
    else if (mes == 11)
    {
        this->mes = "Nov";
    }
    else if (mes == 12)
    {
        this->mes = "Dec";
    }
    else
    {
        this->mes = "null";
    }
}

fecha::fecha()
{
    this->mes = "null";
    this->dia = 0;
    this->año = 0;
    this->mesNum = 0;
}

bool fecha::operator>(const fecha &fecha)
{
    if (this->año > fecha.año)
    {
        return true;
    }
    else if (this->año < fecha.año)
    {
        return false;
    }
    else if (this->mesNum > fecha.mesNum)
    {
        return true;
    }
    else if (this->mesNum < fecha.mesNum)
    {
        return false;
    }
    else if (this->dia > fecha.dia)
    {
        return true;
    }
    else if (this->dia < fecha.dia)
    {
        return false;
    }
    return false; 
}

bool fecha::operator>=(const fecha &fecha)
{
    if (this->año > fecha.año)
    {
        return true;
    }
    else if (this->año < fecha.año)
    {
        return false;
    }
    else if (this->mesNum > fecha.mesNum)
    {
        return true;
    }
    else if (this->mesNum < fecha.mesNum)
    {
        return false;
    }
    else if (this->dia > fecha.dia)
    {
        return true;
    }
    else if (this->dia < fecha.dia)
    {
        return false;
    }
    else if (this->año == fecha.año && this->mesNum == fecha.mesNum && this->dia == fecha.dia)
    {
        return true;
    }
    return false; 
}

bool fecha::operator<(const fecha &fecha)
{
    if (this->año < fecha.año)
    {
        return true;
    }
    else if (this->año > fecha.año)
    {
        return false;
    }
    else if (this->mesNum < fecha.mesNum)
    {
        return true;
    }
    else if (this->mesNum > fecha.mesNum)
    {
        return false;
    }
    else if (this->dia < fecha.dia)
    {
        return true;
    }
    else if (this->dia > fecha.dia)
    {
        return false;
    }
    return false; 
}

bool fecha::operator<=(const fecha &fecha)
{
    if (this->año < fecha.año)
    {
        return true;
    }
    else if (this->año > fecha.año)
    {
        return false;
    }
    else if (this->mesNum < fecha.mesNum)
    {
        return true;
    }
    else if (this->mesNum > fecha.mesNum)
    {
        return false;
    }
    else if (this->dia < fecha.dia)
    {
        return true;
    }
    else if (this->dia > fecha.dia)
    {
        return false;
    }
    else if (this->año == fecha.año && this->mesNum == fecha.mesNum && this->dia == fecha.dia)
    {
        return true;
    }
    return false; 
}

bool fecha::operator==(const fecha &fecha)
{
    if (this->año == fecha.año && this->mesNum == fecha.mesNum && this->dia == fecha.dia)
    {
        return true;
    }
    return false; 
}

void fecha::setMes(const string &mes)
{
    this->mes = mes;
}

void fecha::setMesNum(const int &mesNum)
{
    this->mesNum = mesNum;
}

void fecha::setDia (const int &dia)
{
    this->dia = dia;
}

void fecha::setAño (const int &año)
{
    this->año = año;
}

string fecha::getMes()
{
    return mes;
}

int fecha::getMesNum()
{
    return mesNum;
}

int fecha::getDia()
{
    return dia;
}

int fecha::getAño()
{
    return año;
}