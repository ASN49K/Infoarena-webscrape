#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

ofstream out("euclid2.out");

int n,x,y;

int cmmdc(int a, int b)
{
    if(!b) return a;
    else return cmmdc(b,a%b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        out<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
