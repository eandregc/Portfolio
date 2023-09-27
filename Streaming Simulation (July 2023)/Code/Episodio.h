#ifndef CLASS_EPISODIO_H
#define CLASS_EPISODIO_H

#include "Video.h"
using namespace std;

class Episodio : public Video
{
protected:
int numEpisodio;
int numTemp;
string serie;

public:
Episodio();
Episodio(const int&, const int&, const int& ,const int&,
const string&, const string&, const string&, const Tiempo&);
void setNumEpisodio(const int&);
void setNumTemp(const int&);
void setSerie(const string&);
int getNumEpisodio();
int getNumTemp();
string getSerie();
virtual void muestra();
};

#endif