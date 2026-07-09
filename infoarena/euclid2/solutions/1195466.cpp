#include <iostream>
#include <fstream>
using namespace std;

int a,b;

int euclid(int a, int b)
{
    if (!b) return a;
    return euclid(b,a % b);
}

int main()
{
    int t,aux;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while(t)
    {
    f>>a>>b;
    aux=euclid(a,b);
    g<<aux<<"\n";
    t--;
    }
}
