#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t;

void swich(long *a, long *b)
{
    long aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void solve(long a, long b)
{
    long x;

    if(a<b)swich(&a,&b);

    while(b != 0)
    {
        x = a%b;
        a=b;
        b=x;
    }
    g<<a<<"\n";
}

void read()
{
    long x,y;
    f>>t;
    for(int i=1;i<=t;i++)
        f>>x>>y,solve(x,y);
}
int main()
{
    read();
    return 0;
}
