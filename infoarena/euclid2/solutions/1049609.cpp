#include <iostream>
#include <fstream>

using namespace std;

int euclid(long x,long y)
    {
        long aux;
        while(y)
        {
            aux=x%y;
            x=y;
            y=aux;
        }
        return x;
    }

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    long x,y,aux;
    fin>>x;

    while(fin>>x>>y)
    {
        if(y<x)
        {
            aux=x;
            x=y;
            y=aux;
        }
        if(x==0)
            fout<<y;
        else
            fout<<euclid(x,y);
        fout<<"\n";
    }
    return 0;
}
