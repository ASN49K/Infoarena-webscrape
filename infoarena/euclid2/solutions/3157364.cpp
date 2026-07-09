#include <iostream>
using namespace std;
typedef long long ll;
ll cmmdc(ll a,ll b)
{
    ll r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    ll n,a,b,i;
    for(cin>>n,i=1;i<=n;i++,cin>>a>>b,cout<<cmmdc(a,b)<<'\n');
	return 0;
}
