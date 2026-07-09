#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
long long n,x,j,i,a,b,putere;
int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a;
        b=0;
        for(j=1;j<=a;j++)
        {
            fin>>x;
            b=b^x;
        }
        if(b==0)
            fout<<"NU";
        else fout<<"DA";
    }
    return 0;
}
