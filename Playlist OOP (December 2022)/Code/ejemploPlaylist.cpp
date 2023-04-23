//Ernesto Andre González Castro
//A01741225
#include <iostream>
#include <string>
using namespace std;

#include "playlist.h"

// Método string pedirDatoTexto
// Pide un rato en formato string y lo regresa.
// Entradas: Ninguna
// Salidas: El valor de la variable
string pedirDatoTexto() {
    string dato;
    getline(cin, dato);
    return dato;
}
// Método int pedirDatoTexto
// Pide un rato en formato int y lo regresa.
// Entradas: Ninguna
// Salidas: El valor de la variable
int pedirDatoNumero() {
    string datoTexto;
    getline(cin, datoTexto);
    int datoNum = stoi(datoTexto);
    return datoNum;
}
// Método Cancion crearCancion
// Pide los datos necesarios para crear una cancion.
// Entradas: El nombre de la cancion
// Salidas: Un objeto Cancion con sus variables creadas
Cancion crearCancion(string elNombreDeLaCancion) {
    string generoCancion = pedirDatoTexto();
    string nombreAutor = pedirDatoTexto();
    string apellidoAutor = pedirDatoTexto();
    string nombreAlbum = pedirDatoTexto();
    string mesNacimiento = pedirDatoTexto();
    int diaNacimiento = pedirDatoNumero();
    int anoNacimiento = pedirDatoNumero();
    int duracionHora = pedirDatoNumero();
    int duracionMinuto = pedirDatoNumero();
    int duracionSegundo = pedirDatoNumero();
    Tiempo tiempoIngresado(duracionHora, duracionMinuto, duracionSegundo);
    Fecha fechaIngresada(diaNacimiento, mesNacimiento, anoNacimiento);
    Artista autorIngresado(nombreAutor, apellidoAutor, fechaIngresada);
    Cancion cancion(elNombreDeLaCancion, generoCancion, nombreAlbum, autorIngresado, tiempoIngresado);
    return (cancion);
}
// Main ()
// Inicia solicitando el nombre del objeto Playlist para inicializarla con su nombre. Luego, comienza un ciclo
// while con la condicion de que si no se manda un espacio en blanco o se supera el limite de canciones, este siga 
// mandando a llamar la función de crearCanción. Despúes de crear la Cancion se une a la playlist. Al terminar, 
// se aplican los metodos necesarios para regresar la información que pide la situación problema. 
// Entradas: Ninguna
// Salidas: Niguna
int main () {
string nombrePlaylist = pedirDatoTexto();
// Instancia de Playlist, con su nombre y cantidad de canciones como atributos inicializados. 
Playlist playlistAndre(nombrePlaylist,0);
string nombreCancion;
// Ciclo para pedir canciones hasta que se ponga el espacio en blanco. 
while (playlistAndre.getCantidadDeCanciones() < 31 || nombreCancion != "" || nombreCancion != " ") 
{
    nombreCancion = pedirDatoTexto();
    if (nombreCancion == "") 
        break;
    // Se manda a llamr la función que pide todos los datos para crear un objeto Cancion e inicializa la variable.
    Cancion cancion = crearCancion(nombreCancion);
    // Se aumenta 1 al atríbuto de cantidadDeCanciones en la playlist.
    playlistAndre.setCantidadDeCanciones(playlistAndre.getCantidadDeCanciones()+1);
    // Se agrega la canción a la playlist.
    playlistAndre.setCancionPlaylist(cancion);
}
// Método para sacar la duración total de todas las canciones.
playlistAndre.sacarDuracionTotal();
// Método para sacar la información base de la playlist.
playlistAndre.informacionPlaylist();
// Método para sacar la información base de la playlist con sus canciones en formato general.
playlistAndre.consultarPlaylist();
// Método para cambiar el método de reproducción, en este caso de secuencial a aleatorio. 
playlistAndre.cambioModoReproduccion();
// Método para consultar la canción en la posición deseada, en este caso la número 4.
playlistAndre.consultaCancion(4);
// Método para mostrar un listado de canciones en el modo de reproducción, en este caso en aleatorio. 
playlistAndre.mostrarListaCanciones();
return 0;
}