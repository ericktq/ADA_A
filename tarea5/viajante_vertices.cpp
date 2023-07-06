#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int id;
    double x, y;

    Node(int id, double x, double y) : id(id), x(x), y(y) {}
};

double distance(const Node& node1, const Node& node2) {
    double dx = node1.x - node2.x;
    double dy = node1.y - node2.y;
    return sqrt(dx * dx + dy * dy);
}

bool siguientePermutacion(vector<int>& arr) {
    int n = arr.size();
    int i = n - 2;

    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false; 
    }

    int j = n - 1;
    while (arr[i] >= arr[j]) {
        j--;
    }

    swap(arr[i], arr[j]);
    reverse(arr.begin() + i + 1, arr.end());

    return true;
}

vector<int> Problema_viajante(const vector<Node>& nodes) {
    int n = nodes.size();
    vector<int> path(n);
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }

    double minDist = numeric_limits<double>::infinity();
    vector<int> bestPath;

    do {
        double dist = 0;
        for (int i = 0; i < n - 1; i++) {
            dist += distance(nodes[path[i]], nodes[path[i + 1]]);
        }
        dist += distance(nodes[path[n - 1]], nodes[path[0]]);

        if (dist < minDist) {
            minDist = dist;
            bestPath = path;
        }
    } while (siguientePermutacion(path));

    return bestPath;
}

void printPath(const vector<int>& path) {
    cout<<"Camino: ";
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;
}

int main() {
    vector<Node> nodes = {
        {0, 1, 1},
        {4, 1, 2},
        {2, 4, 2},
        {1, 3, 1},
        {2, 4, 3}
    };

    vector<int> path = Problema_viajante(nodes);
    printPath(path);

    return 0;
}