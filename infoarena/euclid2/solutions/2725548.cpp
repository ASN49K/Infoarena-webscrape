#include <iostream>
#include <fstream>
using namespace std;


int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    g << a <<endl;
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T;
    long long int a,b;
    f >>  T;
    while(0<T)
    {
        f >>a >>b;
        euclid(a,b);
        T--;
    }
    return 0;
}
