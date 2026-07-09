#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int i, m, n, cmmdc, ok, T, k, j;
int main()
{
    fin>>T;
    for(i=1;i<=T;i++)
    {
        cmmdc=0;
        fin>>m>>n;
        for(j=1;j<=m && j<=n;j++)
        {
            if(m%j==0 && n%j==0)cmmdc=j;
        }
        fout<<cmmdc<<endl;
    }

    return 0;
}
