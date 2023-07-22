#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int cambioMonedas(vector<int>& denominaciones, int cantidad) {
    int n = denominaciones.size();
    vector<int> dp(cantidad + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= cantidad; ++i) {
        for (int j = 0; j < n; ++j) {
            if (denominaciones[j] <= i) {
                int subproblema = dp[i - denominaciones[j]];
                if (subproblema != INT_MAX && subproblema + 1 < dp[i]) {
                    dp[i] = subproblema + 1;
                }
            }
        }
    }
    return dp[cantidad];
}

int main() {
    int cantidad = 15;
    vector<int> denominaciones = {1, 5, 10, 25};
    int resultado = cambioMonedas(denominaciones, cantidad);
    cout << "El numero minimo de monedas necesario es: " << resultado << endl;

    return 0;
}
