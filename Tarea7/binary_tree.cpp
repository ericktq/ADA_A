#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

int binaryTree(const vector<Item>& items, int capacity, int currentIdx, int currentWeight, int currentValue) {
    if (currentIdx >= items.size() || currentWeight > capacity) {
        return currentValue;
    }

    int option1 = binaryTree(items, capacity, currentIdx + 1, currentWeight, currentValue);

    int option2 = binaryTree(items, capacity, currentIdx + 1, currentWeight + items[currentIdx].weight, currentValue + items[currentIdx].value);

    return max(option1, option2);
}

int main() {
    int capacity = 10;
    vector<Item> items = {{2, 6}, {5, 8}, {3, 3}, {7, 10}, {4, 4}};

    int maxValue = binaryTree(items, capacity, 0, 0, 0);
    cout << "Max Value: " << maxValue << endl;

    return 0;
}
