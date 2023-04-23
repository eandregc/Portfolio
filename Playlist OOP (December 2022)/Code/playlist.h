//Ernesto Andre González Castro
//A01741225
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Fecha {

    public:
    // Constructor de la clase Fecha con 3 parámetros
    // Se genera una instancia de la clase Fecha, inicializando 3 atributos del objeto
    // Entradas: Valores para los 3 atributos a inicializar
    // Salidas: Ninguna
    Fecha (int elDia, string elMes, int elAno) {
        dia = elDia;
        mes = elMes;
        ano = elAno;
    }
    // Constructor de la clase Fecha sin parámetros
    // Se genera una instancia de la clase Fecha, con atributos iniciales en inexistentes.
    // Entradas: Ninguna
    // Salidas: Ninguna
    Fecha () {
        dia = 0;
        mes = "N/A";
        ano = 0;
    }
    // Método setter setDia
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setDia (int elDia) {
        dia = elDia;
    }
    // Método setter setMes
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setMes (string elMes) {
        mes = elMes;
    }
    // Método setter setAno
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setAno (int elAno) {
        ano = elAno;
    }
    // Método getter getDia
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getDia() {
        return dia;
    }
    // Método getter getMes
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getMes() {
        return mes;
    }
    // Método getter getAno
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getAno() {
        return ano;
    }
    // Método toString duracion
    // Transforma a texto las 3 variables que involucran fecha
    // Entradas: Ninguna
    // Salidas: Las variables en formato de fecha
    string fechaCompleta() {
        string texto;
        if (ano >= 2000)
        texto = to_string(dia) + " de " + (mes) + " del " + to_string(ano);
        else 
        texto = to_string(dia) + " de " + (mes) + " de " + to_string(ano);
        return (texto);
    }

    private:
    string mes;
    int dia, ano;
};

class Tiempo {

    public:
    // Constructor de la clase Tiempo con 3 parámetros
    // Se genera una instancia de la clase Tiempo, inicializando 3 atributos del objeto
    // Entradas: Valores para los 3 atributos a inicializar
    // Salidas: Ninguna
    Tiempo(int lasHoras, int losMinutos, int losSegundos) {
        hora = lasHoras;
        minuto = losMinutos;
        segundo = losSegundos;
    }
    // Constructor de la clase Tiempo sin parámetros
    // Se genera una instancia de la clase Tiempo, con atributos iniciales en 0.
    // Entradas: Ninguna
    // Salidas: Ninguna
    Tiempo () {
        hora = 0;
        minuto = 0;
        segundo = 0;
    }
    // Método setter setHora
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setHora(int lasHoras) {
        hora = lasHoras;
    }
    // Método setter setMinuto
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setMinuto(int losMinutos) {
        minuto = losMinutos;
    }
    // Método setter setSegundo
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setSegundo(int losSegundos) {
        segundo = losSegundos;
    }
    // Método setter setTiempo
    // Asigna el valor de las 3 variables que involucran el tiempo
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setTiempo(int lasHoras, int losMinutos, int losSegundos) {
        hora = lasHoras;
        minuto = losMinutos;
        segundo = losSegundos;
    }
    // Método getter getHora
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getHora() {
        return hora;
    }
    // Método getter getMinuto
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getMinuto() {
        return minuto;
    }
    // Método getter getSegundo
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getSegundo() {
        return segundo;
    }
    // Método toString duracion
    // Transforma a texto las 3 variables que involucran tiempo
    // Entradas: Ninguna
    // Salidas: Las variables en formato de horario
    string duracion() {
        string texto, horaTexto, minutoTexto, segundoTexto;
        horaTexto = to_string(hora);
            if (hora < 10)
            horaTexto = "0" + horaTexto;
        minutoTexto = to_string(minuto);
            if (minuto < 10)
            minutoTexto = "0" + minutoTexto;
        segundoTexto = to_string(segundo);
            if (segundo < 10)
            segundoTexto = "0" + segundoTexto;    
        texto = horaTexto + ":" + minutoTexto + ":" + segundoTexto;
        return texto;
    }

    private:
    int hora;
    int minuto;
    int segundo;
};

class Artista {

    public:
    // Constructor de la clase Artista con 3 parámetros
    // Se genera una instancia de la clase Artista, inicializando 3 atributos del objeto
    // Entradas: Valores para los 3 atributos a inicializar
    // Salidas: Ninguna
    Artista (string elNombre, string elApellido, Fecha laFechaDeNacimiento) {
        nombre = elNombre;
        apellido = elApellido;
        fechaDeNacimiento = laFechaDeNacimiento;
    }
    // Constructor de la clase Artista con 2 parámetros
    // Se genera una instancia de la clase Artista, inicializando 2 atributos del objeto
    // Entradas: Valores para los 2 atributos a inicializar
    // Salidas: Ninguna
    Artista (string elNombre, string elApellido) {
        nombre = elNombre;
        apellido = elApellido;
    }
    // Constructor de la clase Artista con un parámetro
    // Se genera una instancia de la clase Artista, inicializando un atributo del objeto.
    // Entradas: Valores para los 1 atributos a inicializar
    // Salidas: Ninguna
    Artista (Fecha laFechaDeNacimiento) {
        fechaDeNacimiento = laFechaDeNacimiento;
    }
    // Constructor de la clase Artista sin parámetros
    // Se genera una instancia de la clase Artistas, con valores iniciales en inexistentes.
    // Entradas: Ninguna
    // Salidas: Ninguna
    Artista () {
        Fecha fechaInexistente(0,"N/A",0);
        nombre = "N/A";
        apellido = "N/A";
        fechaDeNacimiento = fechaInexistente;
    }
    // Método setter setNombreCompleto
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setNombreCompleto (string elNombre, string elApellido) {
        nombre = elNombre;
        apellido = elApellido;
    }
    // Método setter setNombre
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna 
    void setNombre (string elNombre) {
        nombre = elNombre;
    }
    // Método setter setApellido
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setApellido (string elApellido) {
        apellido = elApellido;
    }
    // Método setter setFechaDeNacimiento
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setFechaDeNacimiento (Fecha laFechaDeNacimiento) {
        fechaDeNacimiento = laFechaDeNacimiento;
    }
    // Método getter getNombreCompleto
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getNombreCompleto () {
        return nombre + " " + apellido;
    }
    // Método getter getNombre
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getNombre () {
        return nombre;
    }
    // Método getter getApellido
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getApellido () {
        return apellido;
    }
    // Método getter getFechaDeNacimiento
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    Fecha getFechaDeNacimiento () {
        return fechaDeNacimiento;
    }
    // Método toString informacion
    // Transforma a texto las 2 variables que involucran Artista 
    // Sumadas a las 3 variables que involucran Fecha en formato toString
    // Entradas: Ninguna
    // Salidas: Las variables en formato de informacion
    string informacion() {
        string texto;
        texto = nombre + apellido + "nacido el " + fechaDeNacimiento.fechaCompleta() + ".";
        return (texto);
    }
    
    private:
    string nombre;
    string apellido;
    Fecha fechaDeNacimiento;
};

class Cancion {

    public:
    // Constructor de la clase Cancion con 5 parámetros
    // Se genera una instancia de la clase Cancion, inicializando 5 atributos del objeto
    // Entradas: Valores para los 5 atributos a inicializar
    // Salidas: Ninguna
    Cancion (string elNombre, string elGenero, string elAlbum, Artista elAutor, Tiempo laDuracion) {
        nombre = elNombre;
        genero = elGenero;
        album = elAlbum;
        autor = elAutor;
        duracionCancion = laDuracion;
    }
    // Constructor de la clase Cancion con 3 parámetros
    // Se genera una instancia de la clase Cancion, inicializando 3 atributos del objeto
    // Entradas: Valores para los 3 atributos a inicializar
    // Salidas: Ninguna
    Cancion (string elNombre, string elGenero, string elAlbum) {
        nombre = elNombre;
        genero = elGenero;
        album = elAlbum;
    }
    // Constructor de la clase Artista con un parámetro
    // Se genera una instancia de la clase Artista, inicializando un atributo del objeto
    // Entradas: Valore para el atributo a inicializar
    // Salidas: Ninguna
    Cancion (Tiempo laDuracion) {
        duracionCancion = laDuracion;
    }
    // Constructor de la clase Cancion sin parámetros
    // Se genera una instancia de la clase Cancion, con valores inexistentes.
    // Entradas: Ninguna
    // Salidas: Ninguna
    Cancion () {
        Fecha fechaInexistente(0,"N/A",0);
        Artista autorInexistente("N/A", "N/A", fechaInexistente);
        Tiempo duracionInexistente(0,0,0);
        nombre = "N/A";
        genero = "N/A";
        album = "N/A";
        autor = autorInexistente;
        duracionCancion = duracionInexistente;
    }
    // Método setter setNombre
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setNombre (string elNombre) {
        nombre = elNombre;
    }
    // Método setter setNombre
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setGenero (string elGenero) {
        genero = elGenero;
    }
    // Método setter setAlbum
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setAlbum (string elAlbum) {
        album = elAlbum;
    }
    // Método setter setAutor
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setAutor (Artista elAutor) {
        autor = elAutor;
    }
    // Método setter setDuracion
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setDuracion (Tiempo laDuracion) {
        duracionCancion = laDuracion;
    }
    // Método getter getNombre
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getNombre () {
        return nombre;
    }
    // Método getter getGenero
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getGenero () {
        return genero;
    }
    // Método getter getAlbum
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getAlbum () {
        return album;
    }
    // Método getter getAutor
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    Artista getAutor () {
        return autor;
    }
    // Método getter getDuracion
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    Tiempo getDuracion () {
        return duracionCancion;
    }
    // Método toString informacion
    // Transforma a texto los atributos del objeto canción
    // Entradas: Ninguna
    // Salidas: Las variables en formato de de información de la cancion
    void informacionCancion() {
        cout << nombre << endl;
        cout << "  " << genero << endl;
        cout << "  " << autor.getNombreCompleto() << endl;
        cout << "  " << album << endl;
        cout << "  " << duracionCancion.duracion() << endl;
    }
    // Método toString duracion
    // Transforma a texto las 3 variables que involucran tiempo
    // Entradas: Ninguna
    // Salidas: Las variables en formato de horario
    string duracion() {
        string texto, horaTexto, minutoTexto, segundoTexto;
        int hora = duracionCancion.getHora();
        int minuto = duracionCancion.getMinuto();
        int segundo = duracionCancion.getSegundo();
        horaTexto = to_string(hora);
            if (hora < 10)
            horaTexto = "0" + horaTexto;
        minutoTexto = to_string(minuto);
            if (minuto < 10)
            minutoTexto = "0" + minutoTexto;
        segundoTexto = to_string(segundo);
            if (segundo < 10)
            segundoTexto = "0" + segundoTexto;    
        texto = horaTexto + ":" + minutoTexto + ":" + segundoTexto;
        return texto;
    }
    // Método getter getNombreCompleto
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getNombreCompleto () {
        return autor.getNombreCompleto();
    }

    private:
    string nombre;
    string genero;
    string album;
    Artista autor;
    Tiempo duracionCancion;
};

class Playlist {

    public:
    // Constructor de la clase Playlist con 2 parámetros
    // Se genera una instancia de la clase Playlist, inicializando 2 atributos del objeto y todos 
    // los huecos de la matriz con un objeto con valores "N/A".
    // Entradas: Valores para los 2 atributos a inicializar
    // Salidas: Ninguna
    Playlist (string elNombrePlaylist, int laCantidadDeCanciones) {
        Cancion cancionInexistente("N/A","N/A","N/A");
        nombrePlaylist = elNombrePlaylist;
        if (laCantidadDeCanciones >= 30) {
            cantidadDeCanciones = 30;
            posicionEnPlaylist = 0;
            modoDeReproduccion = 0;
            for (int ciclo = 0; ciclo < 30; ciclo++) {
                cancionesPlaylist[ciclo] = cancionInexistente;
            }
        }
        else
        cantidadDeCanciones = laCantidadDeCanciones;
        posicionEnPlaylist = 0;
        modoDeReproduccion = 0;
        for (int ciclo = 0; ciclo < 30; ciclo++) {
            cancionesPlaylist[ciclo] = cancionInexistente;
        }
    }
    // Constructor de la clase Playlist sin parámetros
    // Se genera una instancia de la clase Playlist y todos 
    // los huecos de la matriz con un objeto con valores "N/A".
    // Entradas: Ninguna
    // Salidas: Ninguna
    Playlist () {
        Cancion cancionInexistente("N/A","N/A","N/A");
        cantidadDeCanciones = 30;
        posicionEnPlaylist = 0;
        modoDeReproduccion = 0;
        for (int ciclo = 0; ciclo < 30; ciclo++) {
            cancionesPlaylist[ciclo] = cancionInexistente;
        }
    }
    // Método setter setCantidadDeCanciones
    // Asigna el valor de la variable, al ser un array maximo de 30 si se
    // supera este número, se asigna el maximo posible. Que es 30.
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setCantidadDeCanciones (int laCantidadDeCanciones) {
        if (laCantidadDeCanciones > 30)
        cantidadDeCanciones = 30;
        else
        cantidadDeCanciones = laCantidadDeCanciones;
    }
    // Método setter setPosicionEnPlaylist
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setPosicionEnPlaylist (int laPosicionEnPlaylist) {
        posicionEnPlaylist = laPosicionEnPlaylist;
    }
    // Método setter setNombrePlaylist
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setNombrePlaylist (int elNombrePlaylist) {
        nombrePlaylist = elNombrePlaylist;
    }
    // Método setter setDuracionTotal
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setDuracionTotal (Tiempo laDuracion) {
        duracionTotal = laDuracion;
    }
    // Método setter setCancionesPlaylist
    // Asigna el valor de la variable a la posición de la playlist en la que se va
    // y luego le agrega 1 al número de posición en el que se va.
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setCancionPlaylist (Cancion laCancion) {
        cancionesPlaylist[posicionEnPlaylist] = laCancion;
        posicionEnPlaylist++;
    }
    // Método setter setModoDeReproduccion
    // Asigna el valor de la variable
    // Entradas: Valor de la variable
    // Salidas: Ninguna
    void setModoDeReproduccion (int elModoDeReproduccion) {
        if (elModoDeReproduccion >= 1)
        modoDeReproduccion = 1;
        if (elModoDeReproduccion <= 0)
        modoDeReproduccion = 0;
    }
    // Método getter getCantidadDeCanciones
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getCantidadDeCanciones () {
        return cantidadDeCanciones;
    }
    // Método getter getPosicionEnPlaylist
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    int getPosicionEnPlaylist () {
        return posicionEnPlaylist;
    }
    // Método getter getDuracionTotal
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    Tiempo getDuracionTotal () {
        return duracionTotal;
    }
    // Método getter getNombrePlaylist
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getNombrePlaylist () {
        return nombrePlaylist;
    }
    // Método getter getCancionPlaylist
    // Evalua si el numero ingresado esta dentro del total de canciones ya ingresadas a la lista. 
    // Si lo esta, agarra el objeto del array y lo regresa.
    // Si no esta, regresa un objeto de canción llamado "CancionInexistente" 
    // con los tres atributos tipo String con valor de "N/A"
    // Entradas: El numero de la posición de la canción en la playlist
    // Salidas: Valor de la variable 
    Cancion getCancionPlaylist (int elNumero) {
        Cancion cancionInexistente("N/A","N/A","N/A");
        if (elNumero >= 0 && elNumero < posicionEnPlaylist)
        return cancionesPlaylist[elNumero];
        else
        return cancionInexistente;
        ;
    }
    // Método getter getModoDeReproduccion
    // Regresa el valor de la variable
    // Entradas: Ninguna
    // Salidas: Valor de la variable 
    string getModoDeReproduccion () {
        if (modoDeReproduccion = 0)
        return "Sencuencial";
        if (modoDeReproduccion = 1)
        return "Aleatorio";
    }
    // Método sacarDuracionTotal
    // Primero inicializa 3 variables, las cuales involucran el tiempo total de toda la canción.
    // Luego, con un método For se abarcan todas las canciones que fueron ingresadas y se van regresando
    // sus valores en segundos y minutos, y sumando a un contador. 
    // Al finalizar, se toman todos los segundos totales para transformarlos a minutos y la cantidad
    // tomada se le resta a los segundos totales y se le agrega a los minutos totales entre 60.
    // Entradas: Ninguna
    // Salidas: Ninguna
    void sacarDuracionTotal () {
        int horasTotales = 0;
        int minutosTotales = 0;
        int segundosTotales = 0;
        int minutosAHoras = 0;
        int segundosAMinutos = 0;
        Tiempo tiempoCancion;
        for (int recorrerLista = 0; recorrerLista <= cantidadDeCanciones; recorrerLista++) 
        {
            tiempoCancion = cancionesPlaylist[recorrerLista].getDuracion();
            // Recoge las horas totales de cada canción
            horasTotales = horasTotales + tiempoCancion.getHora();
            // Recoge los minutos totales de cada canción
            minutosTotales = minutosTotales + tiempoCancion.getMinuto();
            // Recoge los segundos totales de cada canción
            segundosTotales = segundosTotales + tiempoCancion.getSegundo();
        }
        // Evalua cuantos segundos se pueden transformar a minutos
        segundosAMinutos = segundosTotales/60;
        // Aumenta estos segundos convertidos a minutos a los minutos totales
        minutosTotales = minutosTotales + segundosAMinutos;
        // Resta estos segundos a los segundos totales
        segundosTotales = segundosTotales - segundosAMinutos*60;
        // Evalua cuantos minutos se pueden transformar a horas
        minutosAHoras = minutosTotales/60;
        // Aumenta estos minutos convertidos a horas a las horas totales
        horasTotales = horasTotales + minutosAHoras;
        // Resta estos minutos a los minutos totales
        minutosTotales = minutosTotales - minutosAHoras*60;
        // Settea los valores al atríbuto de la Playlist
        duracionTotal.setHora(horasTotales);
        duracionTotal.setMinuto(minutosTotales);
        duracionTotal.setSegundo(segundosTotales);
    }
    // Método void eliminarUltimaCancion
    // Elimina la ultima canción agregada a la playlist
    // Entradas: Ninguna
    // Salidas: Ninguna
    void eliminarUlimaCancion () {
        Cancion cancionInexistente("N/A","N/A","N/A");
        if (posicionEnPlaylist <= 0)
            ;
        else
            cancionesPlaylist[posicionEnPlaylist--] = cancionInexistente;
    }
    // Método toString informacionPlaylist
    // Transforma a texto los atributos de la clase Playlist, en formato de datos generales.
    // Entradas: Ninguna
    // Salidas: Los atributos en formato de general
    void informacionPlaylist() {
        cout << endl;
        cout << "-Playlist Creada-" << endl;
        cout << "Playlist: " << nombrePlaylist << endl;
        cout << "Cantidad de canciones: " + to_string(cantidadDeCanciones) << endl;
        cout << "Duracion total: " + duracionTotal.duracion() + " hrs"<< endl;
    }
    // Método toString consultarPlaylist
    // Transforma a texto los atributos de la clase Playlist, en formato de datos secuenciales.
    // Entradas: Ninguna
    // Salidas: Las variables en formato secuencial
    void consultarPlaylist() {
        cout << endl;
        cout << "-Playlist Consulta-" << endl;
        cout << "Playlist: " << nombrePlaylist << endl;
        cout << "Cantidad de canciones: " + to_string(cantidadDeCanciones) << endl;
        cout << "Duracion total: " + duracionTotal.duracion() + " hrs" << endl;
        cout << "Modo de ejecucion: Secuencial" << endl;
        cout << "Canciones:" << endl;
        for (int recorrerLista = 0; recorrerLista < cantidadDeCanciones; recorrerLista++)
        {
            string numeroDeCancion = to_string(recorrerLista+1) + ".";
            cout << numeroDeCancion;
            cancionesPlaylist[recorrerLista].informacionCancion();
        }
    }
    // Método toString cambioModoReproduccion
    // Muestra el modo de cambio de modo de reproducción. 
    // Entradas: 0 en caso de Secuencial y 1 en caso de aleatoria
    // Salidas: El modo de ejecución que se va a poner
    void cambioModoReproduccion() {
        cout << endl;
        switch (modoDeReproduccion)
        {
        case 0:
            cout << "-Playlist cambio-" << endl;
            cout << "Modo de ejecucion: Aleatorio" << endl;
            modoDeReproduccion = 1;
            break;
        case 1:
            cout << "-Playlist cambio-" << endl;
            cout << "Modo de ejecucion: Secuencial" << endl;
            modoDeReproduccion = 0;
            break;
        }
    }
    // Método toString consultaCancion
    // Muestra la información de la canción en el numero de posición seleccionado en la Playlist. 
    // Entradas: El numero de cancion
    // Salidas: Las variables en formato consulta
    void consultaCancion(int elNumeroDeCancion) {
        cout << endl;
        cout << "-Cancion consulta-" << endl;
        cout << "Numero de cancion: " << to_string(elNumeroDeCancion) <<  endl;
        cout << "Titulo: " << cancionesPlaylist[elNumeroDeCancion-1].getNombre() <<  endl;
        cout << "Artista: " << cancionesPlaylist[elNumeroDeCancion-1].getNombreCompleto() <<  endl;
        cout << "Album: " << cancionesPlaylist[elNumeroDeCancion-1].getAlbum() <<  endl;
        cout << "Duracion: " << cancionesPlaylist[elNumeroDeCancion-1].duracion() <<  endl;
    }
    // Método aleatorio
    // Regresa un valor al azar entre el minimo y el máximo dados.
    // Entradas: Un valor máximo y un valor minimo
    // salidas: el valor aleatorio
    int aleatorio_en_rango(int minimo, int maximo) {
        return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
    }
    // Método toString mostarListaCanciones
    // Muestra la lista de canciones en el formato de lista, de acuerdo al modo de reproducción.
    // Entradas: Ninguna.
    // Salidas: Los objetos de cancion en formato lista.
    void mostrarListaCanciones() {
        cout << endl;
        cout << "-Lista de reproduccion- " << endl;
        if (modoDeReproduccion = 0) {
            for (int recorrerLista = 0; recorrerLista < cantidadDeCanciones; recorrerLista++) {
            string numeroDeCancion = to_string(recorrerLista+1) + ".";
            cout << numeroDeCancion;
            cancionesPlaylist[recorrerLista].getNombre();
            }
        }
        if (modoDeReproduccion = 1) {
            string cancionesPlaylistAleatorias[cantidadDeCanciones];
            srand(getpid());
            for (int recorrerLista = 0; recorrerLista < cantidadDeCanciones; recorrerLista++) {
                cancionesPlaylistAleatorias[recorrerLista] = cancionesPlaylist[recorrerLista].getNombre();
            }   
            int largoArreglo = sizeof(cancionesPlaylistAleatorias) / sizeof cancionesPlaylistAleatorias[0];
            for (int recorrerLista = 0; recorrerLista < largoArreglo; recorrerLista++)
            // For desde 0 hasta el tamaño de la lista
            for (int recorrerLista = 0; recorrerLista < largoArreglo; recorrerLista++) {
                int indiceAleatorio = aleatorio_en_rango(0, largoArreglo - 1);
                // Cambia el valor presente por uno valor índice aleatorio 
                string temporal = cancionesPlaylistAleatorias[recorrerLista];
                cancionesPlaylistAleatorias[recorrerLista] = cancionesPlaylistAleatorias[indiceAleatorio];
                cancionesPlaylistAleatorias[indiceAleatorio] = temporal;
            }
            for (int recorrerLista = 0; recorrerLista < largoArreglo; recorrerLista++) {
                string numeroDeCancion = to_string(recorrerLista+1) + ".";
                cout << numeroDeCancion << cancionesPlaylistAleatorias[recorrerLista] << endl;
            }
        }
    }
    
    private:
    int cantidadDeCanciones;
    int posicionEnPlaylist;
    int modoDeReproduccion;
    Tiempo duracionTotal;
    string nombrePlaylist;
    Cancion cancionesPlaylist[30];
};
