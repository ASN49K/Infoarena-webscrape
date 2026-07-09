#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,c1,c2,aux;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>c1>>c2;
            while (c2!=0)
    {
        aux=c1%c2;
        c1=c2;
        c2=aux;
    }
    fout<<c1<<"\n";
    }
    return 0;
}
