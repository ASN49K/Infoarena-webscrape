#include <bits/stdc++.h>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int T,a,b;
int cmmdc(int a,int b)
{
    while(b)
    {int r=a%b;
     a=b;
     b=r;
    }
    return a;
}
int main()
{   f>>T;
    for(int i=1;i<=T;i++)
    {   f>>a>>b;
        g<<cmmdc(a,b)<<' ';
    }
    g.close();f.close();return 0;
}
