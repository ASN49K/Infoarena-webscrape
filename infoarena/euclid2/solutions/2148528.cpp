#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b,i;

void Euclid(int a, int b)
{
    int r=a%b;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    g<<a<<"\n";
}

void Read()
{
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a>>b;
        Euclid(a,b);
    }
}

int main()
{
    Read();
    return 0;
}
