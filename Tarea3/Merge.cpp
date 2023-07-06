
#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int const L, int const medio,int const R)
{
    int const array1 = medio - L + 1;
    int const array2 = R - medio;
 
    auto *LArray = new int[array1],
         *RArray = new int[array2];
 
    for (auto i = 0; i < array1; i++)
        LArray[i] = array[L + i];
    for (auto j = 0; j < array2; j++)
        RArray[j] = array[medio + 1 + j];
 
    auto indexOfarray1 = 0, indexOfarray2 = 0;
    int indexOfMergedArray = L;
 
    while (indexOfarray1 < array1
           && indexOfarray2 < array2) {
        if (LArray[indexOfarray1]
            <= RArray[indexOfarray2]) {
            array[indexOfMergedArray]
                = LArray[indexOfarray1];
            indexOfarray1++;
        }
        else {
            array[indexOfMergedArray]
                = RArray[indexOfarray2];
            indexOfarray2++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfarray1 < array1) {
        array[indexOfMergedArray]
            = LArray[indexOfarray1];
        indexOfarray1++;
        indexOfMergedArray++;
    }
 
    while (indexOfarray2 < array2) {
        array[indexOfMergedArray]
            = RArray[indexOfarray2];
        indexOfarray2++;
        indexOfMergedArray++;
    }
    delete[] LArray;
    delete[] RArray;
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int medio = begin + (end - begin) / 2;
    mergeSort(array, begin, medio);
    mergeSort(array, medio + 1, end);
    merge(array, begin, medio, end);
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
    mergeSort(arr, 0, arr_size - 1); 
    cout << "\nArreglo ordenado \n";
    printArray(arr, arr_size);
    return 0;
}
 
