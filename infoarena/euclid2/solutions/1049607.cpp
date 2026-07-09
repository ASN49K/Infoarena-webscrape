#include <iostream>
#include <fstream>

using namespace std;

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
        {
            while(x!=y)
            {
                if(y>x)
                    y=y-x;
                else x=x-y;
            }
        fout<<y;
        }
        fout<<"\n";
    }
    return 0;
}
