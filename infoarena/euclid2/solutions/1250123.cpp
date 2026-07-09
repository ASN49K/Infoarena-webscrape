#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        gcd(b,a%b);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int tc;
    ll a,b;
    cin>>tc;
    while(tc--)
    {
        cin>>a>>b;
        cout<<gcd(a,b)<<"\n";
    }
}
