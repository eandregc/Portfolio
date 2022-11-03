#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Realize the cuadratic formula procedure.//
void formulaCuadratica (float valorA, float valorB, float valorC, float resultante1, float resultante2, float discriminante) {
    int contador=0;
    while (contador != 2)
        //First "X" (-)//
        if (contador == 0){
        resultante1= ((-1*valorB) - sqrt(discriminante)) / (2*valorA);
        contador++;
        //Second "X" (+)//
        } else {
        resultante2= ((-1*valorB) + sqrt(discriminante)) / (2*valorA);
        contador++; 
        }
    //Printing the results.//
    cout << "X1: " << setprecision(2) << resultante1 << "\n" << "X2: " << setprecision(2) << resultante2 << "\n";
}

//Ask for the input values in A, B, C. (Ax^2 + Bx + C).//
int main(){
float valorA, valorB, valorC, resultante1, resultante2, discriminante;
cout << "Introduce A: ",cin >> valorA;
cout << "Introduce B: ",cin >> valorB;
cout << "Introduce C: ",cin >> valorC;
//Gets the discriminant (B^2 - 4AC)//
discriminante= ((valorB*valorB) - (4*valorA*valorC));
    /*If the discriminant is a negative result, the sqrt(B^2 - 4AC) 
    will get a imaginray result, making impossible to get the real "X's".*/
    if (discriminante<0) {
    cout << "Cannot be performed";
    return 0;
    /*If the discriminant is a positive result, the program can move foraward 
    in the next steps on the cuadratic formula.*/
    } else {
    formulaCuadratica(valorA, valorB, valorC, resultante1, resultante2, discriminante);
    return 0;
    }
}