#include <iostream>
#include <fstream>

using namespace std;

long n;

long Euclid(long x, long y)
{
    long r = x%y;
    long aux=0;
    while(r!=0)
    {
         aux = y%r;
         y = r;
         r = aux;
    }
    return y;
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    fin>>n;
    for(int i=0;i<n;i++)
    {
        long a,b;
        fin>>a>>b;
        fout<<Euclid(a,b)<<endl;;
    }
    return 0;
}
