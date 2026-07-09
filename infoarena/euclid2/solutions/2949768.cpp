#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void cmmdc(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<'\n';
}
int main()
{
    int t,i,x,y;
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>x>>y;
        cmmdc(x,y);

    }
    return 0;
}
