#include <iostream>
#include <stdio.h>

using namespace std;
int cmmdc(int a,int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    int n,a,b;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        cout<<cmmdc(a,b)<<"\n";

    }
    return 0;
}
