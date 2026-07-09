#include <fstream>
#include <iostream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

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
    int n, m, cmmdc=1,i;

    f>>n;
    f>>m;
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
    g<<m;*/
    int aux;
    if(m>n)
    {
        aux=n;
        n=m;
        m=aux;

    }
   /* while(n%m!=0)
    {
        aux=n%m;
        n=m;
        m=aux;
    }
    g<<m;*/
    m=euclid(m, n);
    g<<m;
    g<<m;

    return 0;
}
