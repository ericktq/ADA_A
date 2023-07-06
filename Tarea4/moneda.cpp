#include <iostream>
#include <climits>
using namespace std;

void Cambio(int tip_moneda[], int tipos_moneda, int monto, int numMonedas[], int moneda_usadas[]) {
    numMonedas[0] = 0; 

    for (int i = 1; i <= monto; i++) {
        for (int j = 0; j < tipos_moneda; j++) {
            if (tip_moneda[j] <= i && numMonedas[i - tip_moneda[j]] + 1 < numMonedas[i]) {
                numMonedas[i] = numMonedas[i - tip_moneda[j]] + 1;
                moneda_usadas[i] = tip_moneda[j];
            }
        }
    }
}

int main() {

    int monto=0;
    cout <<"Monto: ";
    cin>> monto;

    int tip_monedas=0;
    cout<<"Ingrese el numero de tipos de monedas: ";
    cin>>tip_monedas;

    int* tip_moneda=new int[tip_monedas];
    cout<<"Ingrese los tipos de monedas: "<<endl;
    for (int i = 0; i < tip_monedas; i++) {
        cin >> tip_moneda[i];
    }


    int* numMonedas=new int[monto + 1];
    int* moneda_usadas=new int[monto + 1];

    for (int i = 1; i <= monto; i++) {
        numMonedas[i] = INT_MAX;
    }

    Cambio(tip_moneda, tip_monedas, monto, numMonedas, moneda_usadas);

   
    int cambio[10];
    int valor = monto;
    int tamCambio = 0;
    while (valor > 0) {
        cambio[tamCambio] = moneda_usadas[valor];
        valor -= moneda_usadas[valor];
        tamCambio++;
    }

    cout << "El cambio de " << monto << " se puede hacer con " << tamCambio << " monedas: ";
    for (int i = 0; i < tamCambio; i++) 
        cout << cambio[i] << " ";
    
    cout << endl;

    return 0;
}