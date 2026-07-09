#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T, a, b;

void Euclid2(int a, int b)
{
    if(a < b)
    {
        int aux = a;
        a = b;
        b = aux;
    }
    int r = a % b;
    while(r)
    {
        a = b;
        b = r;
        r = a % b;
    }
    out << b << endl;
}

void citire_afisare()
{
    in >> T;
    for(int i = 1; i <= T; i++)
    {
        in >> a >> b;
        Euclid2(a, b);
    }
}
int main()
{
    citire_afisare();
    return 0;
}
