#include "Pelicula.h"

// Instancia de la clase Pelicula
// Entrada: null
// Salida: null
Pelicula::Pelicula()
:Video()
{
    
}

// Instancia de la clase Pelicula
// Entrada: 4 variables int, 3 variables string y 1 variable tiempo 
// Salida: null
Pelicula::Pelicula(const int &_idVideo, const int &_calificacion, const string &_titulo, 
const string &_genero, const Tiempo &_duracion)
:Video(_idVideo, _calificacion, _titulo, _genero, _duracion)
{

}

// Metodo toString
// Se encarga de desplegar las variables en formato muestra (Pelicula)
// Entrada: null
// Salida: null
void Pelicula::muestra()
{
    cout << "p " <<  idVideo << " " << titulo << " " << genero << " " << duracion.getHora() 
    << " " << calificacion;
}

