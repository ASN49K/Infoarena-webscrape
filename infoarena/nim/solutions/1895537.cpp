#include <fstream>
#include<iostream>
using namespace std;
#define DIM 10000
int a,s,n,t,poz;
char buff[DIM];
ifstream f("nim.in");
inline void R(int &x)
{
    x=0;
    while(buff[poz]<'0'||buff[poz]>'9')
        if(++poz==DIM)
    {
        poz=0;
        f.read(buff,DIM);
    }
    while(buff[poz]>='0'&&buff[poz]<='9')
    {
        x=x*10+buff[poz]-'0';
        if(++poz==DIM)
        {
            poz=0;
            f.read(buff,DIM);
        }
    }
}
int main()
{
    R(t);
    ofstream g("nim.out");
    while(t--)
    {
        R(n);
        s=0;
        while(n--)
        {
            R(a);
            s^=a;
        }
        if(s)
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
