#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int peso;
    int valor;
};

int mochila(int capacidad, vector<Item>& items) {
    int n = items.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacidad; ++w) {
            if (items[i - 1].peso > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].valor + dp[i - 1][w - items[i - 1].peso]);
            }
        }
    }
    return dp[n][capacidad];
}

int main() {
    int capacidad_mochila = 10;
    vector<Item> items = {{2, 3}, {4, 5}, {3, 2}, {5, 8}, {1, 4}};
    int resultado = mochila(capacidad_mochila, items);
    cout << "El valor máximo que se puede obtener es: " << resultado << endl;

    return 0;
}
