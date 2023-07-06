#include <iostream>
using namespace std;
 
int potencia(int x, int y)
{
    int temp;
    if (y == 0)
        return 1;
    temp = potencia(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else {
        if (y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}

int main()
{
    int x = 2;
    int y = 3;
    cout <<x<< " elevado a "<<y<<" es "<< potencia(x, y);
    return 0;
}
