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
        if(m%n==0)cmmdc=n;
            else if(n%m==0)cmmdc=m;
                else
        for(j=1;j*2<=m && j*2<=n;j++)
        {
            if(m%j==0 && n%j==0)
            {
                cmmdc=j;
                while(ok==1)
                {
                    ok=0;
                    if(m%j==0 && n%j==0)
                    {
                        ok=1;
                        n/=j;
                        m/=j;
                    }
                }
            }
        }


        fout<<cmmdc<<endl;
    }

    return 0;
}
