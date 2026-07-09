#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long i,n,a,b,aux;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        aux=1;
        while (b!=0)
        {
            aux=b;
            b=a%b;
            a=aux;
        }
        g<<aux<<"\n";
    }
}
