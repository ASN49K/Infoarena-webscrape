#include <iostream>
#include <cstdio>
using namespace std;
int a,b,r,n,i;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a>>b;
        while (b)
        {
            r=b;
            b=a%b;
            a=r;
        }
        cout<<a<<'\n';
    }
}
