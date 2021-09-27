/*Elabore una función que, dado un número entero que se obtiene desde teclado,realice un conteo como el siguiente: Suponiendo que el valor ingresado es 3:
1
2
3
1
2
*/

#include <iostream>

using namespace std;

int main (void)
{   
    int numero; 
    
    cout << "Ingrese el numero al que quiere que el conteo sea dirigido" << endl;
    cin >> numero; 
    for(int i=1; i<=numero;i++) 
    cout << i << " "; 

    for(int listaInversa = numero-1; 
    1 <= listaInversa;listaInversa--) cout << listaInversa << " "; 
    return 1; 
}