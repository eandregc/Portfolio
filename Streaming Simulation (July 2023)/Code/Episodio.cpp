#include "Episodio.h"

// Instancia de la clase Episodio
// Entrada: null
// Salida: null
Episodio::Episodio()
:Video()
{
    numEpisodio = 0;
    numTemp = 0;
    serie = "null"; 
}

// Instancia de la clase Episodio
// Entrada: 4 variables int, 3 variables string y 1 variable tiempo 
// Salida: null
Episodio::Episodio(const int &_numEpisodio, const int &_numTemp, const int &_idVideo,
const int &_calificacion, const string &_serie, const string &_titulo, const string &_genero,
const Tiempo &_duracion)
:Video(_idVideo, _calificacion, _titulo, _genero, _duracion)
{
    numEpisodio = _numEpisodio;
    numTemp = _numTemp;
    serie = _serie; 
}

// Metodo setter numEpisodio
// Entrada: 1 variable int
// Salida: null
void Episodio::setNumEpisodio(const int &_numEpisodio)
{
    numEpisodio = _numEpisodio;
}

// Metodo setter numTemp
// Entrada: 1 variable int
// Salida: null
void Episodio::setNumTemp(const int &_numTemp)
{
    numTemp = _numTemp;
}

// Metodo setter serie
// Entrada: 1 variable int
// Salida: null
void Episodio::setSerie(const string &_serie)
{
    serie = _serie;
}

// Metodo getter numEpisodio
// Entrada: null
// Salida: 1 variable int
int Episodio::getNumEpisodio()
{
    return numEpisodio;
}

// Metodo getter numTemp
// Entrada: null
// Salida: 1 variable int
int Episodio::getNumTemp()
{
    return numTemp;
}

// Metodo getter serie
// Entrada: null
// Salida: 1 variable int
string Episodio::getSerie()
{
    return serie;
}

// Metodo toString
// Se encarga de desplegar las variables en formato muestra (Episodio)
// Entrada: null
// Salida: null
void Episodio::muestra()
{
    cout << "e " <<  idVideo << " " << titulo << " " << genero << " " << duracion.getHora() 
    << " " << calificacion << " " << serie << " " << numEpisodio << " " << numTemp;
}

