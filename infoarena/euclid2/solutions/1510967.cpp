#include <iostream>
#include <cstdio>
using namespace std;
long long a,b,r,n,i;
int main()
{
    std::ios::sync_with_stdio(false);
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
