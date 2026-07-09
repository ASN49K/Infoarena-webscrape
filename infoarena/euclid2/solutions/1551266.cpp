#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned long T = 0;
    f>>T;
    unsigned long a, b, aux;
    while (T > 0)
    {
        f>>a>>b;
        while (b!=0)
        {
            aux = b;
            b = a%b;
            a = aux;
        }
        g<<a<<"\n";
        T--;
    }
    f.close();
    g.close();
    return 0;
}
