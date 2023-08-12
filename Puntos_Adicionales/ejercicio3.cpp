//Diseñe un algoritmo B&B para resolver el problema de la asignación con la
//siguiente matriz de costes:
//f1 f2 f3 f4
//d1 94 1 54 68
//d2 74 10 88 82
//d3 62 88 8 76
//d4 11 74 81 21
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Assignment {
    int row, col;
    Assignment(int r, int c) : row(r), col(c) {}
};

struct CompareAssignment {
    bool operator()(const Assignment& a, const Assignment& b) {
        return a.row > b.row; 
    }
};

int calculateBound(const vector<vector<int>>& costMatrix, const vector<int>& assignment) {
    int bound = 0;
    vector<bool> assignedRow(costMatrix.size(), false);
    vector<bool> assignedCol(costMatrix[0].size(), false);

    for (size_t i = 0; i < assignment.size(); ++i) {
        int row = i;
        int col = assignment[i];
        bound += costMatrix[row][col];
        assignedRow[row] = true;
        assignedCol[col] = true;
    }

    for (size_t i = 0; i < assignedRow.size(); ++i) {
        if (!assignedRow[i]) {
            int minCost = numeric_limits<int>::max();
            for (size_t j = 0; j < assignedCol.size(); ++j) {
                if (!assignedCol[j] && costMatrix[i][j] < minCost) {
                    minCost = costMatrix[i][j];
                }
            }
            bound += minCost;
        }
    }

    return bound;
}

pair<int, vector<int>> assignmentBnB(const vector<vector<int>>& costMatrix) {
    int n = costMatrix.size();
    priority_queue<Assignment, vector<Assignment>, CompareAssignment> pq;
    vector<int> initialAssignment(n, -1); //

    int initialBound = calculateBound(costMatrix, initialAssignment);
    pair<int, vector<int>> bestSolution(numeric_limits<int>::max(), vector<int>());

    pq.push(Assignment(initialBound, -1)); 

    while (!pq.empty()) {
        Assignment currAssignment = pq.top();
        pq.pop();

        if (currAssignment.row != -1 && currAssignment.row >= n) {
            int cost = calculateBound(costMatrix, currAssignment.colAssignment);
            if (cost < bestSolution.first) {
                bestSolution.first = cost;
                bestSolution.second = currAssignment.colAssignment;
            }
            continue;
        }

        for (int col = 0; col < n; ++col) {
            if (find(currAssignment.colAssignment.begin(), currAssignment.colAssignment.end(), col) == currAssignment.colAssignment.end()) {
                vector<int> newAssignment = currAssignment.colAssignment;
                newAssignment.push_back(col);

                int newBound = calculateBound(costMatrix, newAssignment);
                pq.push(Assignment(newBound, newAssignment));
            }
        }
    }

    return bestSolution;
}

int main() {
    vector<vector<int>> costMatrix = {
        {94, 1, 54, 68},
        {74, 10, 88, 82},
        {62, 88, 8, 76},
        {11, 74, 81, 21}
    };

    pair<int, vector<int>> solution = assignmentBnB(costMatrix);

    cout << "Best Cost: " << solution.first << endl;
    cout << "Best Assignment: ";
    for (int col : solution.second) {
        cout << col << " ";
    }
    cout << endl;

    return 0;
}
