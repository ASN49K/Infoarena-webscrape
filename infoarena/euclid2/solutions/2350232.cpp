#include <bits/stdc++.h>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int cmmdc (int a,int b)
{
    if (b==0)
    return a;
    return cmmdc(b,a%b);
}
int main()
{
    int a,b,n,i;
    in>>n;
    for(i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
