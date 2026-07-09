#include <fstream>
#include <iostream>

using namespace std;

unsigned cmmdc(unsigned a, unsigned b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    unsigned n,i,a,b,aux;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a<b){aux=a; a=b; b=aux;}
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
