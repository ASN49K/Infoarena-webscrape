#include <iostream>
#include <fstream>
using namespace std;
int n, i, aux, a, b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            aux=a%b;
            a=b;
            b=aux;
        }
        g<<a<<"\n";
    }
    return 0;
}
