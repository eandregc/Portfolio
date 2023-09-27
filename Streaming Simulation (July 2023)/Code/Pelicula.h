#ifndef CLASS_PELICULA_H
#define CLASS_PELICULA_H

#include "Video.h"
using namespace std;

class Pelicula : public Video
{
private:

public:
Pelicula();
Pelicula(const int&, const int&, const string&,
const string&, const Tiempo&);
virtual void muestra();
};

#endif