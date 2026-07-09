#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main() 
{
    int n, a, b, aux;
    f >> n;
    while (n) 
    {
        --n;
        f >> a >> b;
        while (b)
        {
            aux = a;
            a = b;
            b = aux % b;
        }
        g << a << '\n';
    }

    return 0;
}
