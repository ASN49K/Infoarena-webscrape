#include <iostream>
#include <cstdio>
using namespace std;
int euclid(int a,int b)
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
int a,b,n;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<euclid(a,b)<<"\n";
    }
    return 0;
}
