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
        while(n!=m)
        {
            while(n>m)n-=m;
            while(m>n)m-=n;
        }

        cmmdc=n;
        fout<<cmmdc<<endl;
    }

    return 0;
}
