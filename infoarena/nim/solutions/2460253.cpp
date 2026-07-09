#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int main()
{
    int n,i,t,sum,a,j;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>n;
        sum=0;
        for(j=1;j<=n;j++)
        {
            fin>>a;
            sum=sum^a;
        }
        if(sum)
            fout<<"DA"<<'\n';
        else fout<<"NU"<<'\n';
    }
    return 0;
}
