#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");



inline int cmmdc(int,int);

int main()
{

    int t;
    f>>t;
    for(int i=1;i<=t;i++)
    {
        int a,b;
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}

inline int cmmdc(int a,int b)
{
    int r=0;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;

    }
    return a;
}
