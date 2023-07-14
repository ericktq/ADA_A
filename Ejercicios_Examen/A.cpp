#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int num;

    while (cin >> num) {
        numbers.push_back(num);
        sort(numbers.begin(), numbers.end());

        int size = numbers.size();
        int mediana;

        if (size % 2 == 0) {
            mediana = (numbers[size/2 - 1] + numbers[size/2]) / 2;
        } else {
            mediana = numbers[size/2];
        }
        cout << mediana << endl;
    }
    return 0;
}