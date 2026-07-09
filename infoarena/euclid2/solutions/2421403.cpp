#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");
ofstream g("date.out");

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
