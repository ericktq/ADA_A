#include <iostream>
#include <vector>

using namespace std;

int mochila(int cap, int pesos[], int valores[], int n) {
    int** dp=new int*[n + 1];
    for (int i = 0; i <= n; i++) 
        dp[i] = new int[cap + 1];

    for (int i = 0; i <= n; i++) 
        dp[i][0] = 0;
    
    for (int j = 0; j <= cap; j++) 
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            if (pesos[i - 1] <= j) 
                dp[i][j] = max(valores[i - 1] + dp[i - 1][j - pesos[i - 1]], dp[i - 1][j]);
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];

    for (int i = 0; i <= n; i++)
        delete[] dp[i];
    
    delete[] dp;
}

int main() {
    int n=0;
    cout << "Numero de elementos: ";
    cin >> n;

    int* pesos=new int[n];
    int* valores=new int[n];

    cout << "Pesos de los elementos: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> pesos[i];
    }

    cout << "Valores de los elementos: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    int cap;
    cout << "Capacidad de la mochila: ";
    cin >> cap;

    int maxValue = mochila(cap, pesos, valores, n);

    cout << "El beneficio total es: " << maxValue << endl;

    delete[] pesos;
    delete[] valores;

    return 0;
}