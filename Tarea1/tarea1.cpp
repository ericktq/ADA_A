#include <vector> 
#include <list>
#include <iostream>
using namespace std;

class CArithmetic
{
private:

public:
static double Addition (double a, double b);
static double Substraction (double a, double b);
static double Multiplication (double a, double b);
static double Division (double a, double b);
};


double CArithmetic::Division(double a, double b)
{
    if ( b == 0.0 )
        throw (int)0; // an exceptions is thrown here
    return a/b;
}


unsigned long fibo(unsigned n)
{
if( n < 2 )
return 1;
unsigned long f1 = 0, f2 = 1;
unsigned long output;
do
{
output = f1 + f2;
f1 = f2;
f2 = output;
}while(--n >= 2);
return output;
}

int bsearch(double a[], double key, int l, int u)
{
    int m;
    if (u<l)
        return -1;
    m = (l+u) / 2;
    if (a[m] == key)
        return m;
    if (a[m] < key)
        return bsearch(a, key, l, m-1);
    else
        return bsearch(a, key, m+1, u);
}
typedef unsigned long ulong;
static ulong fact_helper(ulong a, ulong n){
    if (n == 0)
        return a;
    else
        return fact_helper(a*n, n-1);
}
ulong fact(ulong n){
    return fact_helper(1, n);
}

template <typename Container> void Write(Container &ds, ostream &os){
    Container::iterator iter = ds.begin();
    for( ; iter != ds.end() ; iter++ )
        os << *iter << "\n";
}
int main(int argc, char* argv[]){
    list<float> mylist;
    vector<float> myvector;
    for( int i = 0 ; i < 10 ; i++ ){
        mylist .push_back( i );
        myvector.push_back(i+50);
    }
    Write(mylist, cout);
    Write(myvector, cout);
    return 0;
}