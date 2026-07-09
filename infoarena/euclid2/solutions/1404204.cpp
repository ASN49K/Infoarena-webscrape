#include <iostream>
#include <stdio.h>
using namespace std;
int n,x,y;
void euclid(int &a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y; euclid(x,y);
        cout<<x<<"\n";
    }
    return 0;
}
