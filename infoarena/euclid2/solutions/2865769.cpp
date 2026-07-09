#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n;
int x,y;
int CMMDC(int a, int b)
{
    if(a>b)swap(a,b);
    while(a!=0)
    {
        int r=b%a;
        b=a;
        a=r;
    }
   fout<<b<<'\n';
}
int main()
{
    fin>>n;
    while(n)
    {
        --n;
        fin>>x>>y;
        CMMDC(x,y);
    }
    return 0;
}
