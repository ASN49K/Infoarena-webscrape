#include <fstream>
#include <iostream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a, int b)
{
    if(a%b==0)
        return b;
    else
    {
        return euclid(b, a%b);
    }
}

int main()
{
    int n, m, a, b, cmmdc=1,i;

    f>>m;
    for(i=1;i<=n;++i)
    {
        f>>a>>b;
        g<<euclid(a,b);
    }
/*
    if(n<m)
    {
        for(i=2;i<=n;++i)
        {
            while(n%i==0&&m%i==0)
            {
                cmmdc*=i;
                n/=i;
                m/=i;
            }
        }
    }
    cout<<cmmdc;
    while(n!=m)
    {
        if(m>n)
        {
            m-=n;
        }
        else
        {
            n-=m;
        }
    }
    g<<m;
    int aux;
    if(m>n)
    {
        aux=n;
        n=m;
        m=aux;

    }
    while(n%m!=0)
    {
        aux=n%m;
        n=m;
        m=aux;
    }
    g<<m;*/

    return 0;
}
