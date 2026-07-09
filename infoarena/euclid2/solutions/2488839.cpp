#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long i, m, n, cmmdc, ok, T, k, j;
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
        cmmdc=0;
        fin>>m>>n;
        while(m!=0)
        {
           k=n%m;
           n=m;
           m=k;
        }

        cmmdc=n;
        fout<<cmmdc<<endl;
    }

    return 0;
}
