#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int functie(int a, int b)
{
    if(!b)
    {
        return a;
    }
    else
    {
        return functie(b, a%b);
    }
}

int main()
{
    int t, contor=0;
    long long a, b;
    f>>a>>b;
    g<<functie(a, b);
    return 0;
}
