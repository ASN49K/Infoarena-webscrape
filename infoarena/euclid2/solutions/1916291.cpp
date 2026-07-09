#include <iostream>
#include <fstream>
using namespace std;
int a,b,n;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int n,int m)
{
    int r;
    while(m)
    {
        r=n%m;
        n=m;
        m=r;
    }
    return n;
}
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }

    return 0;
}
