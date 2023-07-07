#include <iostream>
#include <vector>

using namespace std;

struct Tarea {
    string nombre;
    int duracion;
    int valor;
};

void PTareas(const vector<Tarea>& tareas, int duracionMax) {
    int n = tareas.size();

    vector<vector<int>> valores(n + 1, vector<int>(duracionMax + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= duracionMax; j++) {
            if (tareas[i - 1].duracion <= j) {
                valores[i][j] = max(valores[i - 1][j], tareas[i - 1].valor + valores[i - 1][j - tareas[i - 1].duracion]);
            } else {
                valores[i][j] = valores[i - 1][j];
            }
        }
    }

    int valorOptimo = valores[n][duracionMax];
    vector<Tarea> tareasSelec;

    int i = n, j = duracionMax;
    while (i > 0 && j > 0) {
        if (valores[i][j] != valores[i - 1][j]) {
            tareasSelec.push_back(tareas[i - 1]);
            j -= tareas[i - 1].duracion;
        }
        i--;
    }

    cout << "Valor optimo: " << valorOptimo << endl;
    cout << "Tareas seleccionadas: " << endl;
    for (int i = tareasSelec.size() - 1; i >= 0; i--) {
        cout << tareasSelec[i].nombre << endl;
    }
}

int main() {

    vector<Tarea> tareas = {{"Tarea 1", 3, 20}, {"Tarea 2", 1, 15},  {"Tarea 3", 1, 10}, {"Tarea 4", 3, 7}, {"Tarea 3", 1, 5},{"Tarea 4", 3, 3} };
    int duracionMax = 5;

    PTareas(tareas, duracionMax);

    return 0;
}
