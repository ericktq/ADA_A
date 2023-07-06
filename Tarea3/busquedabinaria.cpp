#include <iostream>
using namespace std;

int binarySearch(int array[], int bajo, int alto, int objetivo){
    int mitad=(bajo+alto)/2;
    if(bajo>alto)
        return -1;
    if(objetivo == array[mitad])
        return mitad;
    if(objetivo < array[mitad])
        return binarySearch(array, bajo, mitad-1,objetivo);
    if(objetivo>array[mitad])
        return binarySearch(array, mitad+1,alto, objetivo);
}
int binarySearch2(int array[],int n, int objetivo){
    int bajo=0;
    int alto=n;
    int mitad=0;
    while (bajo<alto){
        mitad=(bajo+alto)/2;
        if(objetivo==array[mitad])
            return mitad;
        else if(objetivo<array[mitad])
            alto=mitad;
        else if(objetivo>array[mitad])
            bajo=mitad+1;
    }
    return -1;
}
int main(){
    int array[]={23,44,62,11};
    int objetivo=62;
    int n=sizeof(array)/sizeof(int);
    int esta=binarySearch2(array,n,objetivo);
   
    if(esta)
        cout<<"Se encontro el numero en el orden : "<<objetivo+1;
    else 
        cout<<"No se encontro el numero "<<endl;
    return 0;
}