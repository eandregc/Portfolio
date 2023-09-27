#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "fecha.h"
#include "tiempo.h"
#include "ip.h"
#include "error.h"
#include <cstdlib>
using namespace std;

// Swap function.
// Input: vector, index a, index b.
// Output: void.
// Swap the elements of the vector.
template<class T>
void swap(vector<T> &list, int a, int b) 
{
    // Validamos que sean diferentes
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// Pivot function Date.
// Input: vector, left, right.
// Output: int.
// Get the pivot.
template<class T>
int getPivotDate(vector<T> &list, int left, int right)
{
    // Get the pivot.
    T pivot = list[right];
    // Get the index of the smaller element.
    int smallerIndex = left - 1;
    // Iterate through the list.
    for (int i = left; i < right; i++)
    {
        // If the current element is smaller than the pivot.
        if (pivot.getFecha() > list[i].getFecha())
        {
            // Increment the index of the smaller element.
            smallerIndex++;
            // Swap the elements.
            swap(list, smallerIndex, i);
        }
    }
    // Swap the elements.
    swap(list, smallerIndex + 1, right);
    // Return the index of the smaller element.
    return smallerIndex + 1;
}

// Quick sort Date.
// Input: vector, left, right.
// Output: void.
// Sort the vector.
void quickSortDate(vector<error> &list, int left, int right)
{
    // If the left is smaller than the right.
    if (left < right)
    {
        // Get the pivot.
        int pivot = getPivotDate(list, left, right);
        // Sort the elements before and after the pivot.
        quickSortDate(list, left, pivot - 1);
        quickSortDate(list, pivot + 1, right);
    }
}

// Pivot function Time.
// Input: vector, left, right.
// Output: int.
// Get the pivot.
template<class T>
int getPivotTime(vector<T> &list, int left, int right)
{
    // Get the pivot.
    T pivot = list[right];
    // Get the index of the smaller element.
    int smallerIndex = left - 1;
    // Iterate through the list.
    for (int i = left; i < right; i++)
    {
        // If the current element is smaller than the pivot.
        if (pivot.getTiempo() > list[i].getTiempo())
        {
            // Increment the index of the smaller element.
            smallerIndex++;
            // Swap the elements.
            swap(list, smallerIndex, i);
        }
    }
    // Swap the elements.
    swap(list, smallerIndex + 1, right);
    // Return the index of the smaller element.
    return smallerIndex + 1;
}

// Quick sort Time.
// Input: vector, left, right.
// Output: void.
// Sort the vector.
void quickSortTime(vector<error> &list, int left, int right)
{
    // If the left is smaller than the right.
    if (left < right)
    {
        // Get the pivot.
        int pivot = getPivotTime(list, left, right);
        // Sort the elements before and after the pivot.
        quickSortTime(list, left, pivot - 1);
        quickSortTime(list, pivot + 1, right);
    }
}

// Pivot function IP.
// Input: vector, left, right.
// Output: int.
// Get the pivot.
template<class T>
int getPivotIp(vector<T> &list, int left, int right)
{
    // Get the pivot.
    T pivot = list[right];
    // Get the index of the smaller element.
    int smallerIndex = left - 1;
    // Iterate through the list.
    for (int i = left; i < right; i++)
    {
        // If the current element is smaller than the pivot.
        if (pivot.getIp() > list[i].getIp())
        {
            // Increment the index of the smaller element.
            smallerIndex++;
            // Swap the elements.
            swap(list, smallerIndex, i);
        }
    }
    // Swap the elements.
    swap(list, smallerIndex + 1, right);
    // Return the index of the smaller element.
    return smallerIndex + 1;
}

// Quick sort IP.
// Input: vector, left, right.
// Output: void.
// Sort the vector.
void quickSortIp(vector<error> &list, int left, int right)
{
    // If the left is smaller than the right.
    if (left < right)
    {
        // Get the pivot.
        int pivot = getPivotIp(list, left, right);
        // Sort the elements before and after the pivot.
        quickSortIp(list, left, pivot - 1);
        quickSortIp(list, pivot + 1, right);
    }
}

// Binary search between two dates and append to a new vector.
// Input: vector, new vector, left, right, start date, end date.
// Output: void.
// Search the vector.
void binarySearchDate(vector<error> &list, vector<error> &newList, int left, int right, fecha fecha1, fecha fecha2)
{
    // If the left is smaller than the right.
    if (left <= right)
    {
        // Get the middle.
        int middle = (left + right) / 2;
        
        // If the current element's date is within the specified range, add it to the new list.
        if (list[middle].getFecha() >= fecha1 && list[middle].getFecha() <= fecha2)
        {
            // Append the element to the new list.
            newList.push_back(list[middle]);
        }

        // If the middle is smaller than the end date, search in the right.
        if (list[middle].getFecha() < fecha2)
        {
            binarySearchDate(list, newList, middle + 1, right, fecha1, fecha2);
        }

        // If the middle is larger than the start date, search in the left.
        if (list[middle].getFecha() > fecha1)
        {
            binarySearchDate(list, newList, left, middle - 1, fecha1, fecha2);
        }
    }
}

// Binary search between two times and append to a new vector.
// Input: vector, new vector, left, right, start time, end time.
// Output: void.
// Search the vector.
void binarySearchTime(vector<error> &list, vector<error> &newList, int left, int right, tiempo tiempo1, tiempo tiempo2)
{
    // If the left is smaller than the right.
    if (left <= right)
    {
        // Get the middle.
        int middle = (left + right) / 2;
        
        // If the current element's time is within the specified range, add it to the new list.
        if (list[middle].getTiempo() >= tiempo1 && list[middle].getTiempo() <= tiempo2)
        {
            // Append the element to the new list.
            newList.push_back(list[middle]);
        }

        // If the middle is smaller than the end time, search in the right.
        if (list[middle].getTiempo() < tiempo2)
        {
            binarySearchTime(list, newList, middle + 1, right, tiempo1, tiempo2);
        }

        // If the middle is larger than the start time, search in the left.
        if (list[middle].getTiempo() > tiempo1)
        {
            binarySearchTime(list, newList, left, middle - 1, tiempo1, tiempo2);
        }
    }
}

// Binary search between two dates and times and append to a new vector.
// Input: vector, new vector, left, right, start date, end date, start time, end time.
// Output: void.
// Search the vector.
void binarySearchDateAndTime(vector<error> &list, vector<error> &newList, int left, int right, fecha fecha1, fecha fecha2, tiempo tiempo1, tiempo tiempo2)
{
    // If the left is smaller than the right.
    if (left <= right)
    {
        // Get the middle.
        int middle = (left + right) / 2;
        
        // If the current element's date is within the specified range, add it to the new list.
        if (list[middle].getFecha() >= fecha1 && list[middle].getFecha() <= fecha2 && list[middle].getTiempo() >= tiempo1 && list[middle].getTiempo() <= tiempo2)
        {
            // Append the element to the new list.
            newList.push_back(list[middle]);
        }
        
        // If the middle is smaller than the end rage, search in the right.
        if (list[middle].getFecha() < fecha2 && list[middle].getTiempo() < tiempo2)
        {
            binarySearchDateAndTime(list, newList, middle + 1, right, fecha1, fecha2, tiempo1, tiempo2);
        }
        {
            binarySearchDateAndTime(list, newList, middle + 1, right, fecha1, fecha2, tiempo1, tiempo2);
        }

        // If the middle is larger than the start range, search in the left.
        if (list[middle].getFecha() > fecha1 && list[middle].getTiempo() > tiempo1)
        {
            binarySearchDateAndTime(list, newList, left, middle - 1, fecha1, fecha2, tiempo1, tiempo2);
        }
    }
}

int main()
{
    // Open file
    string filename = "log603.txt";
    ifstream inputFile(filename);

    // Create vector
    vector <error> items;
    vector <error> dentroDelRango;
    string line;

    // Define stringstream and delimiter
    stringstream ss;
    char delimiter = ' ';
    
    while (getline(inputFile, line)) {
        // Clear stringstream for new line
        ss.clear();
        ss.str(line);

        // Variables
        string nombre;
        string mes;
        int dia, año;
        string hora, minuto, segundo;
        string ipNueva;

        // Read elements separated by delimiter
        ss >> mes; // Read the first element as the name
        ss >> dia; // Read the second element as the day
        ss >> año; // Read the third element as the year
        // Divide the fourth element by delimiter
        getline(ss, hora, ':'); // Read the first element as the hour
        getline(ss, minuto, ':'); // Read the second element as the minute
        getline(ss, segundo, ' '); // Read the third element as the second
        ss >> ipNueva;
        
        // Read the rest of the line as the last name
        getline(ss, nombre);

        // Create objects
        fecha fechaNueva(mes, dia, año);
        tiempo tiempoNuevo(hora, minuto, segundo);
        ip ipNuevo(ipNueva);
        error errorNuevo(nombre, fechaNueva, tiempoNuevo, ipNuevo);
        // Push the item to the vector
        items.push_back(errorNuevo);
    }

    int input;
    // Menu loop
    system("cls");
    while (input != 3)
    {
        if (input != 3)
        {
            system("cls");
        }
        cout << "Bienvenido al sistema de multiusos" << endl;
        cout << "¿Que desea hacer?" << endl;
        cout << "1. Ordenar los datos" << endl;
        cout << "2. Buscar un rango de datos" << endl;
        cout << "3. Salir" << endl;
        cout << endl;
        cout << "Ingrese el numero de la opcion que desea: ";
        cin >> input;
        system("cls");
        switch (input)
        {
        case 1: // Sort
            cout << "Bienvenido al sistema de ordenamiento" << endl;
            cout << "1. Ordenar por fecha" << endl;
            cout << "2. Ordenar por hora" << endl;
            cout << "3. Ordenar por fecha y hora" << endl;
            cout << "4. Ordenar por ip" << endl;
            cout << endl;
            cout << "Ingrese el numero de la opcion que desea: ";
            cin >> input;
            system("cls");
            // Order the vector
            switch (input)
            {
            case 1: // Sort by date 
            
                quickSortDate(items, 0, items.size() - 1);
                for (int i = 0; i < items.size(); i++) 
                {
                    items[i].printError();
                }
                break;
            case 2: // Sort by time
                quickSortTime(items, 0, items.size() - 1);
                for (int i = 0; i < items.size(); i++) 
                {
                    items[i].printError();
                }
                break;
            case 3: // Sort by ip
                quickSortIp(items, 0, items.size() - 1);
                for (int i = 0; i < items.size(); i++) 
                {
                    items[i].printError();
                }   
                break;
            default:
                cout << "Opcion no valida, vuelve a empezar :(";
                cout << endl;
                cout << "Presione 0 para salir...";
                cin >> input;
                system("cls");
                break;
            }
            cout << endl;
            cout << "Presione 0 para salir...";
            cin >> input;
            system("cls");
            break;
        case 2: // Search
            cout << "Bienvenido al sistema de busqueda" << endl;
            cout << "1. Buscar por fecha" << endl;
            cout << "2. Buscar por hora" << endl;
            cout << "3. Buscar por fecha y hora" << endl;
            cout << endl;
            cout << "Ingrese el numero de la opcion que desea: ";
            cin >> input;
            system("cls");
            fecha fecha1;
            fecha fecha2;
            tiempo tiempo1;
            tiempo tiempo2;
            ip ip1;
            ip ip2;
            // Search the vector
            switch (input)
            {
            case 1: // Search by date
                int mes, dia, año;
                cout << "Ingrese todos los datos en númerico (YYYY/MM/DD)" << endl;
                cout << "Ingrese el año de inicio: " << endl; 
                cin >> año;
                cout << "Ingrese el mes de inicio: " << endl;
                cin >> mes;
                cout << "Ingrese el dia: " << endl;
                cin >> dia;
                fecha1.setMesNum(mes);
                fecha1.setDia(dia);
                fecha1.setAño(año);
                cout << endl;
                cout << "Ingrese el año de fin: " << endl;
                cin >> año;
                cout << "Ingrese el mes de fin: " << endl;
                cin >> mes;
                cout << "Ingrese el dia: " << endl;
                cin >> dia;
                fecha2.setMesNum(mes);
                fecha2.setDia(dia);
                fecha2.setAño(año);
                cout << endl;
                system("cls");
                binarySearchDate(items, dentroDelRango, 0, items.size() - 1, fecha1, fecha2);
                // Order the vector
                quickSortDate(dentroDelRango, 0, dentroDelRango.size() - 1);
                for (int i = 0; i < dentroDelRango.size(); i++) 
                {
                    dentroDelRango[i].printError();
                }
                break;
            case 2: // Search by time
                int hora, minuto, segundo;
                cout << "Ingrese todos los datos en númerico (HH:MM:SS)" << endl;
                cout << "Ingrese la hora de inicio: " << endl;
                cin >> hora;
                cout << "Ingrese el minuto de inicio: " << endl;
                cin >> minuto;
                cout << "Ingrese el segundo: " << endl;
                cin >> segundo;
                tiempo1.setHora(hora);
                tiempo1.setMinuto(minuto);
                tiempo1.setSegundo(segundo);
                cout << endl;
                cout << "Ingrese la hora de fin: " << endl;
                cin >> hora;
                cout << "Ingrese el minuto de fin: " << endl;
                cin >> minuto;
                cout << "Ingrese el segundo: " << endl;
                cin >> segundo;
                tiempo2.setHora(hora);
                tiempo2.setMinuto(minuto);
                tiempo2.setSegundo(segundo);
                cout << endl;
                system("cls");
                binarySearchTime(items, dentroDelRango, 0, items.size() - 1, tiempo1, tiempo2);
                // Order the vector
                quickSortTime(dentroDelRango, 0, dentroDelRango.size() - 1);
                for (int i = 0; i < dentroDelRango.size(); i++) 
                {
                    dentroDelRango[i].printError();
                }
                break;
            case 3: // Search by date and time
                cout << "Ingrese todos los datos en númerico (YYYY/MM/DD)" << endl;
                cout << "Ingrese el año de inicio: " << endl; 
                cin >> año;
                cout << "Ingrese el mes de inicio: " << endl;
                cin >> mes;
                cout << "Ingrese el dia: " << endl;
                cin >> dia;
                fecha1.setMesNum(mes);
                fecha1.setDia(dia);
                fecha1.setAño(año);
                cout << endl;
                cout << "Ingrese el año de fin: " << endl;
                cin >> año;
                cout << "Ingrese el mes de fin: " << endl;
                cin >> mes;
                cout << "Ingrese el dia: " << endl;
                cin >> dia;
                fecha2.setMesNum(mes);
                fecha2.setDia(dia);
                fecha2.setAño(año);
                cout << endl;
                cout << "Ingrese todos los datos en númerico (HH:MM:SS)" << endl;
                cout << "Ingrese la hora de inicio: " << endl;
                cin >> hora;
                cout << "Ingrese el minuto de inicio: " << endl;
                cin >> minuto;
                cout << "Ingrese el segundo: " << endl;
                cin >> segundo;
                tiempo1.setHora(hora);
                tiempo1.setMinuto(minuto);
                tiempo1.setSegundo(segundo);
                cout << endl;
                cout << "Ingrese la hora de fin: " << endl;
                cin >> hora;
                cout << "Ingrese el minuto de fin: " << endl;
                cin >> minuto;
                cout << "Ingrese el segundo: " << endl;
                cin >> segundo;
                tiempo2.setHora(hora);
                tiempo2.setMinuto(minuto);
                tiempo2.setSegundo(segundo);
                cout << endl;
                system("cls");
                binarySearchDateAndTime(items, dentroDelRango, 0, items.size() - 1, fecha1, fecha2, tiempo1, tiempo2);
                // Order the vector
                quickSortTime(dentroDelRango, 0, dentroDelRango.size() - 1);
                for (int i = 0; i < dentroDelRango.size(); i++) 
                {
                    dentroDelRango[i].printError();
                }
                break;
            default:
                cout << "Opcion no valida, vuelve a empezar :(";
                cout << endl;
                cout << "Presione 0 para salir...";
                cin >> input;
                system("cls");
                break;
            }
            cout << endl;
            cout << "Presione 0 para salir...";
            cin >> input;
            system("cls");
            break;
        }
    }
    // Save the sorted vector to a file
    ofstream outputFile("output603.txt");
    // Save in a format that can be read by the program
    for (int i = 0; i < items.size(); i++) 
    {
        outputFile << items[i].getFecha().getMes() << " " << items[i].getFecha().getDia() << " " << items[i].getFecha().getAño() << " " << items[i].getTiempo().getHoraTexto() << ":" << items[i].getTiempo().getMinutoTexto() << ":" << items[i].getTiempo().getSegundoTexto() << " " << items[i].getIp().getIp() << " " << items[i].getNombre() << endl;
    }
    // Save the searched vector to a file
    ofstream outputFile2("range603.txt");
    for (int i = 0; i < dentroDelRango.size(); i++) 
    {
        outputFile2 << dentroDelRango[i].getFecha().getMes() << " " << dentroDelRango[i].getFecha().getDia() << " " << dentroDelRango[i].getFecha().getAño() << " " << dentroDelRango[i].getTiempo().getHoraTexto() << ":" << dentroDelRango[i].getTiempo().getMinutoTexto() << ":" << dentroDelRango[i].getTiempo().getSegundoTexto() << " " << dentroDelRango[i].getIp().getIp() << " " << dentroDelRango[i].getNombre() << endl;
    }
    // Close file
    outputFile.close();
    outputFile2.close();
    inputFile.close();
    return 0;
}
