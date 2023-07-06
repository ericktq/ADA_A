#include <iostream>
using namespace std;
  

int partition(int arr[], int low, int high)
{

    int pivote = arr[high];
  
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivote) {

            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
  
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << "Elementos \n";
    printArray(arr, arr_size); 
    quickSort(arr, 0, arr_size - 1);
    cout << "Arreglo ordenado: " << endl;
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
