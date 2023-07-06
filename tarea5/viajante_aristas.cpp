#include <iostream>
#include <vector>

using namespace std;

const int INF = 999999;  

int nodoMasCerca(vector<bool>& visitadas, const vector<vector<int>>& grafo, int nodoActual) {
    int nodoCercana = -1;
    int distMin = INF;

    for (int i = 0; i < grafo.size(); ++i) {
        if (!visitadas[i] && grafo[nodoActual][i] < distMin) {
            distMin = grafo[nodoActual][i];
            nodoCercana = i;
        }
    }

    return nodoCercana;
}

vector<int> vecinoMasCercano(const vector<vector<int>>& grafo) {
    int n = grafo.size();
    vector<bool> visitadas(n, false);
    vector<int> camino;
    int nodoActual = 0;  

    visitadas[nodoActual] = true;
    camino.push_back(nodoActual);

    for (int i = 0; i < n - 1; ++i) {
        int sigNodo = nodoMasCerca(visitadas, grafo, nodoActual);
        visitadas[sigNodo] = true;
        camino.push_back(sigNodo);
        nodoActual = sigNodo;
    }

    camino.push_back(0);

    return camino;
}

int main() {
    vector<vector<int>> grafo = {
        {0, 2, 9, 10},
        {1, 0, 6, 4},
        {15, 7, 0, 8},
        {6, 3, 12, 0}
    };

    vector<int> camino = vecinoMasCercano(grafo);

    cout << "Camino: ";
    for (int ciudad : camino) {
        cout << ciudad << " ";
    }
    cout << endl;

    return 0;
}