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
        r=a%b;
        if (!r) cout<<min(a,b)<<'\n';
        else
        {
            while (b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            cout<<a<<'\n';
        }
    }
}
