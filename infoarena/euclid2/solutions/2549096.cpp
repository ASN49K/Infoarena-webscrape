#include <bits/stdc++.h>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a,int b)
{
    if(a<b)
    {
        a+=b;
        b=a-b;
        a-=b;
    }
    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int n,a,b;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<'\n';
    }
    return 0;
}
