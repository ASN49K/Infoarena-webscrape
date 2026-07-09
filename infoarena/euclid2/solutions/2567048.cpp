#include <bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,r;
inline int cmmdc(int a,int b)
{
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>n;
    while(n--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
}
