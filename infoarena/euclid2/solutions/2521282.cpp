#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T,a,b;

void Euclid(int a,int b)
{
    while(b)
    {
        int aux=a%b;
        a=b;
        b=aux;
    }
    g<<a<<'\n';
}

int main()
{
    f>>T;
    for(int t=1;t<=T;t++)
    {
        f>>a>>b;
        Euclid(a,b);
    }

    return 0;
}
