#include <iostream>
using namespace std;
int main(){
    int N;
    cout<<"N= ";
    cin>>N;

    //Ejercicio 1
    for (int i = 0; i < N; i++) // N
        if (i%2==0)             //1
            cout<<i<<endl;      //1
    //Complejidad: O(N)

    //Ejercicio 2
    for (int  i = 0; i < N; i++) // N
        if (i%2==0)              // 1
            cout<<i<<endl;       // 1
    for (int i = 0; i < N; i++)  // N
        if (i%2 !=0)             // 1
            cout<<i<<endl;       // 1
    //Complejidad: O(N)
    
    //Ejercicio 3
    for (int i = 0; i < N; i++)  //N
        for (int j = 0; j < N; j++) // N
            cout<< i<<","<<j;       //1
            cout<<" "<<endl;        /1
    //Complejidad: O(N^2)
        
    //Ejercicio 4 
    int i=1;            // 1
    while (i<N){        // log n
        cout<<i;        // 1

        i=i*2;          //1
        cout<<""<<endl;
    }
    //Complejidad: O(log N)
    
    //Ejercicio 5
    string A{0,1,2,3,4};   //1
    string B{5,6,7,8,9};   // 1
    for (int i = 0; i <A.length(); i++)   // A
        for (int j = 0;j< B.length(); j++)  // B
            cout<<A[i]<<","<<B[j];       // 1
    //Complejidad: O(A*B)

    //Ejercicio 6
    for (int i = 0; i < N; i++){ // n
        int j=1;                  // 1
        while (j<N){             // log n
            cout<<j;               // 1
            j=j*2;                 // 1
        }  
    }
    //Complejidad: O(N*logN)

    //Ejercicio 7
    N=100;                     //1
    if(N%2==0)                  //1
        cout<<"par";           // 1
    else                        //1
        cout<<"impar";             //1
    //Complejidad: O(1)
}