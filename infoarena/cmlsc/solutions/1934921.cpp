#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("vase.in");
ofstream fout("vase.out");
long long int v[100003];
char c[100003];
int x;
long long int suma=0;
int main()
{
    int n,i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>v[i]>>c[i];
        suma+=v[i]/2;
    }
    fout<<suma<<'\n';
    fin>>x;
    suma=0;
    for(i=1; i<x; i++)
        suma+=v[i]/2;
    long long int in,sf;
    if(c[x]=='D')
    {
        in=suma-v[x]/2;
        sf=suma+v[x]/2;
    }
    else
    {
        in=-suma-v[x]/2;
        sf=-suma+v[x]/2;
    }
    for(i=x+1; i<=n; i++)
        if(c[i]=='D')
        {
            in-=v[i]/2;
            sf-=v[i]/2;
        }
        else
        {
            in+=v[i]/2;
            sf+=v[i]/2;
        }

    if( in>=0 && sf>0)fout<<sf<<" D"<<'\n'<<in<<" D"<<'\n';
    else if( in<0 && sf<=0)fout<<-in<<" S"<<'\n'<<-sf<<" S"<<'\n';
    else fout<<-in<<" S"<<'\n'<<sf<<" D"<<'\n';
    }
