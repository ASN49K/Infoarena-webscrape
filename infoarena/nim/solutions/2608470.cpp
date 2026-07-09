#include<iostream>
#include<fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int v[10001],n,t,inm;
int main()
{
    f>>t;
    for(int k=1;k<=t;k++)
    {
        f>>n;
        for(int i=1;i<=n;i++)
        {
            f>>v[i];
        }
        inm=v[1];
        for(int i=2;i<=n;i++)
        {
            inm=inm^v[i];
        }
        if(inm==0)
            g<<"NU";
        else
            g<<"DA";
        g<<"\n";
    }
}
