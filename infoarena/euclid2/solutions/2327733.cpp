#include <bits/stdc++.h>
using namespace std;
int n;
int cmmdc (int a,int b)
{
    int r;
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
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
