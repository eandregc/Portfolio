#include "Tiempo.h"
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Usuario.h"
#include <fstream>
#include <stdlib.h>
// system("cls");  Limpiar Consola

int main()
{
    system("cls");
    // Input del while
    int input = 6;
    // Inputs secundarios
    int input2;
    // Inputs de tipos
    int inputInt;
    string inputStr;
    char inputChar;
    // Variables de Clave
    int idVideo, calificacion, numEpisodio, numTemp, duracion;
    string titulo, genero, serie;
    // Creacion de lectura de archivo
    ifstream archivo;
    // Array de videos 
    Video *videos[320];
    // Creacion del usuario
    Usuario Andre;
    // ids del usuario
    int idUsuario;
    // Iniciar interfaz 
    while (input != 0)
    {
        cout << "-Bienvenido selecciona tu opción-" << endl << "\n";
        cout << "1. Cargar archivo de datos" << endl; 
        cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << endl; 
        cout << "3. Ver datos del usuario y modificarlos" << endl; 
        cout << "4. Agregar video a la lista del usuario" << endl; 
        cout << "5. Calificar un video" << endl; 
        cout << "0. Salir" << endl << "\n";
        cout << "Opcion seleccionada: "; 
        cin >> input;
        while (input < 0 || input > 5)
                {
                    system("cls");
                    cout << "-Bienvenido selecciona tu opción-" << endl << "\n";
                    cout << "1. Cargar archivo de datos" << endl; 
                    cout << "2. Mostrar los videos en general con una cierta calificación o de un cierto género" << endl; 
                    cout << "3. Ver datos del usuario y modificarlos" << endl; 
                    cout << "4. Agregar video a la lista del usuario" << endl; 
                    cout << "5. Calificar un video" << endl; 
                    cout << "0. Salir" << endl << "\n";
                    cout << "Opcion seleccionada: "; 
                    cin >> input;
                }
        system("cls");
        switch (input)
        {
        // Opcion leer la base de datos 
        case 1:
            system("cls");
            // Checar si el archivo esta abierto
            if (archivo.is_open())
            {
                // Contador 
                int contador = 0;
                while (archivo >> inputChar)
                {
                    // Leer si es un episodio
                    if (inputChar == 'e')
                    {
                        archivo >> idVideo >> titulo >> genero >> duracion >> calificacion >> serie >> numEpisodio >> numTemp;
                        Tiempo dura(duracion,0,0);
                        videos[contador] = new Episodio(numEpisodio, numTemp, idVideo, calificacion, serie, titulo, genero, dura);
                        contador++;
                    }
                    // Leer si es una pelicula
                    else
                    {
                        archivo >> idVideo >> titulo >> genero >> duracion >> calificacion;
                        Tiempo dura(duracion,0,0);
                        videos[contador] = new Pelicula(idVideo, calificacion, titulo, genero, dura);
                        contador++;
                    }
                }
                // Mandar un mensaje cuando se carguen los videos al array
                cout << "Carga lista! -> :)" << endl; 
                // Boton de continuación
                cout << "Presiona 6 para continuar: "; 
                cin >> input2;
                // Verificación de datos
                while (input2 != 6)
                {
                    system("cls");
                    cout << "Carga lista! -> :)" << endl; 
                    cout << "Presiona 6 para continuar: "; 
                    cin >> input2;
                }
                // Limpiar consola
                system("cls");
            }
            // Si no estaba abierto, abrir el archivo
            else
            {
                archivo.open("Ejemplo-1.txt");
                cout << "Ahora el archivo esta abierto ->" << endl; 
                cout << "(Debes volver a seleccionar esta opción para agregar los videos)" << endl << "\n"; 
                cout << "Presiona 6 para continuar: "; 
                cin >> input2;
                while (input2 != 6)
                {
                    system("cls");
                    cout << "Ahora el archivo esta abierto ->" << endl; 
                    cout << "(Debes volver a seleccionar esta opción para agregar los videos)" << endl << "\n"; 
                    cout << "Presiona 6 para continuar: "; 
                    cin >> input2;
                }
                system("cls");
            }
            break;
        // Opcion mostrar los videos por calificación o por genero
        case 2:
            cout << "-Mostrar los videos en general con una cierta calificación o de un cierto género-" << endl << "\n";
            cout << "1. Calificación" << endl; 
            cout << "2. Género" << endl << "\n"; 
            cout << "Opcion seleccionada (1-2): "; 
            cin >> inputInt;
            // Selecciión de modo
            while (inputInt < 1 || inputInt > 2)
                {
                    system("cls");
                    cout << "-Mostrar los videos en general con una cierta calificación o de un cierto género-" << endl << "\n";
                    cout << "1. Calificación" << endl; 
                    cout << "2. Género" << endl << "\n"; 
                    cout << "Opcion seleccionada (1-2): "; 
                    cin >> inputInt;
                }
            // Opción mostrar por calificación
            if (inputInt == 1)
            {
                system("cls");
                cout << "Con que calificación (1-5): ";
                cin >> inputInt;
                while (inputInt < 1 || inputInt > 5)
                {
                    system("cls");
                    cout << "Con que calificación (1-5): ";
                    cin >> inputInt;
                }
                system("cls");
                // Buscar en el array los videos con esa calificación
                for (int i = 0; i < 320; i++)
                {
                    if (videos[i]->getCalificacion() == inputInt)
                    {
                        videos[i]->muestra();
                        cout << endl;
                    }
                }
                cout << "Presiona 6 para continuar: "; 
                cin >> input2;
                while (input2 != 6)
                {
                    system("cls");
                    cout << endl << "Presiona 6 para continuar: "; 
                    cin >> input2;
                }
                system("cls");
            }
            // Opción mostrar por genero
            else
            {   
                system("cls");
                cout << "Con que género (nombre): ";
                cin >> inputStr;
                system("cls");
                // Buscar en el array con esa calificación
                for (int i = 0; i < 320; i++)
                {
                    if (videos[i]->getGenero() == inputStr)
                    {
                        videos[i]->muestra();
                        cout << endl;
                    }
                }
                cout << endl << "Presiona 6 para continuar: "; 
                cin >> input2;
                system("cls");
            }
            break;
        // Opcion ver datos y modificarlos
        case 3:
            cout << "-Ver datos del usuario y modificarlos-" << endl << "\n";
            cout << "Nombre de cuenta: " << Andre.getNombre() << endl;
            cout << "Cuenta del usuario: " << Andre.getCuenta() << endl << "\n";
            cout << "- Videos en la lista del usuario- " << endl << "\n";
            Andre.setContadorVideos();
            // Contar todos los videos que hay en la clase usuario
            idVideo = Andre.getContadorVideos();
            // Solo proceder si hay por lo menos 1 video
            if (idVideo > 0)
            {
                // Recorrer el array solo dependiendo el número de videos
                for (int i = 0; i < idVideo; i++)
                {
                    int elId = Andre.getUnIdMisVideos(i);
                    for (int i = 0; i < 320; i++)
                    {
                        if (elId == videos[i]->getIdVideo())
                        {
                            // Mostrar esos videos 
                            videos[i]->muestra();
                            cout << endl;
                        }
                    }
                }
            }
            else
            {
                // Si al inicio no encontró videos, mostrar un mensaje
                cout << "No hay videos" << endl;
            }
            cout << endl;
            // Modificar datos
            cout << "1. Modificar datos" << endl; 
            // Regresar al menu principal
            cout << "2. Regresar a la pantalla principal" << endl << "\n"; 
            cout << "Opcion seleccionada (1-2): "; 
            cin >> inputInt;
            while (inputInt < 1 || inputInt > 2)
            {
                system("cls");
                cout << "1. Modificar datos" << endl; 
                cout << "2. Regresar a la pantalla principal" << endl << "\n"; 
                cout << "Opcion seleccionada (1-2): ";
                cin >> inputInt;
                system("cls");
            }
            system("cls");
            // Opción de modificar datos
            if (inputInt == 1)
            {
                system("cls");
                cout << "Que quieres modificar: " << endl << "\n";
                cout << "1. Nombre" << endl;
                cout << "2. Cuenta del usuario" << endl << "\n";
                cout << "Opcion seleccionada (1-2): "; 
                cin >> inputInt;
                while (inputInt < 1 || inputInt > 2)
                {
                    system("cls");
                    cout << "Que quieres modificar: " << endl << "\n";
                    cout << "1. Nombre" << endl;
                    cout << "2. Cuenta del usuario" << endl;
                    cout << "Opcion seleccionada (1-2): "; 
                    cin >> inputInt;
                }
                // Modificar el nombre 
                if (inputInt == 1)
                {
                    system("cls");
                    cout << "Nuevo nombre de la cuenta: ";
                    cin >> inputStr;
                    Andre.setNombre(inputStr);
                    system("cls");
                    cout << "El nuevo nombre de la cuenta es: " 
                    << Andre.getNombre() << endl << "\n";
                }
                // Modificar la cuenta
                else
                {
                    system("cls");
                    cout << "Nueva cuenta del usuario: ";
                    cin >> inputStr;
                    Andre.setCuenta(inputStr);
                    system("cls");
                    cout << "La nueva cuenta del usuario es: " 
                    << Andre.getCuenta() << endl << "\n";
                }
                cout << "Presiona 6 para continuar: "; 
                cin >> input2;
                while (input2 != 6)
                {
                    system("cls");
                    cout << endl << "Presiona 6 para continuar: "; 
                    cin >> input2;
                }
            }
            system("cls");
            break;
        // Opción agregar videos a la lista del usuario 
        case 4:
            cout << "-Agregar video a la lista del usuario-" << endl << "\n";
            cout << "Puedes presionar 0 para regresar al menu."; 
            cout << endl << "\n"; 
            cout << "Video a agregar (id): ";
            cin >> inputInt;
            if (inputInt == 0)
            {
                // Hola no hago nada solo salto para volver al menu
            }
            // Si no presiona 0, coloca un id
            else
            {
                input2 = 0;
                // Busca ese id en el array
                for (int i = 0; i < 320; i++)
                {
                    if (inputInt == videos[i]->getIdVideo())
                    {
                        input2++;
                    }
                }
                while (input2 == 0)
                {
                    /* Verificar si ese id esta en la base.
                    Si no esta, solicitar otro id,
                    esto hasta que ponga uno valido */
                    system("cls");
                    cout << "No se encuentra un video con ese id en la base de datos -> :(" << endl << "\n";
                    cout << "Selecciona otro video (id): ";
                    cin >> inputInt;
                    for (int i = 0; i < 320; i++)
                    {
                        if (inputInt == videos[i]->getIdVideo())
                        {
                            input2++;
                        }
                    }
                }
                system("cls");
                /* Si puso un id valido, meter el id al array 
                de misIds de la clase usuario */
                Andre+=inputInt;
                cout << "El video ";
                for (int i = 0; i < 320; i++)
                {
                    if (inputInt == videos[i]->getIdVideo())
                    {
                        // Mostrar el video que fue añadido al array
                        videos[i]->muestra();
                    }
                }
                // Mensaje de de añadido
                cout << "se ha añadido a la cuenta!" << endl << "\n";
                cout << "Presiona 6 para continuar: "; 
                cin >> input2;
                while (input2 != 6)
                {
                    system("cls");
                    cout << endl << "Presiona 6 para continuar: "; 
                    cin >> input2;
                }
            }
            system("cls");
            break;
        // Opción calificar un video
        case 5:
            cout << "-Calificar un video-" << endl << "\n";
            cout << "Titulo seleccionado (id): "; 
            cin >> input2;
            system("cls");
            cout << "Haz seleccionado: ";
            // Recorrer el array hasta encontrar ese id y mostrarlo
            for (int i = 0; i < 320; i++)
            {
                if (videos[i]->getIdVideo() == input2)
                {
                    videos[i]->muestra();
                    cout << endl << "\n";
                } 
            }
            // Elegir la calificación
            cout << "Calificación seleccionada (1-5): "; 
            cin >> inputInt;
            while (inputInt < 1 || inputInt > 5)
            {
                system("cls");
                cout << "Con que calificación (1-5): ";
                cin >> inputInt;
            }
            system("cls");
            cout << "Haz calificado ";
            // Mostrar el video calificado
            for (int i = 0; i < 320; i++)
            {
                if (videos[i]->getIdVideo() == input2)
                {
                    videos[i]->setCalificacion(inputInt);
                    videos[i]->muestra();
                } 
            } 
            // Mostrar la calificación seleccioanda 
            cout << " con (" << inputInt << ")" << endl << "\n";
            cout << "Presiona 6 para continuar: "; 
            cin >> input2;
            while (input2 != 6)
            {
                system("cls");
                cout << endl << "Presiona 6 para continuar: "; 
                cin >> input2;
            }
            system("cls");
            break;
        // Cerrar el servicio de streaming
        case 0:
            cout << "Gracias por participar!"; 
            break;
        default:
            break;
        }
    }
    // Cerrar el archivo que se abrió al inicio 
    archivo.close();
    return 0;
}