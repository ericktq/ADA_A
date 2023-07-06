#include <iostream>
using namespace std;

int busquedaBinaria(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int medio = l + (r - l) / 2;
        if (arr[medio] == x)
            return medio;
        if (arr[medio] > x)
            return busquedaBinaria(arr, l, medio - 1, x);

        return busquedaBinaria(arr, medio + 1, r, x);
    }

    return -1;
}
 
int main()
{
    int arr[] = { 3 , 4 , 5 , 9 , 12 };
    int x = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = busquedaBinaria(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "El elemento no esta en el arreglo"
        : cout << "El elemento está en la posición  " << result;
    return 0;
}
