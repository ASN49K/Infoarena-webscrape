#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i;
int euclid(int a,int b)
{
    int aux;
    while(b!=0)
    {
        aux=b;
        b=b%a;
        a=aux;
    }
    return a;
}
int main()
{
    int a,b;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
