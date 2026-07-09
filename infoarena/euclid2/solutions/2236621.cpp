#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define lli long long int 
#define mod 1000000007
 

ll gcdx(ll n,ll m)
{
	if(!m) return n;
	return gcdx(m,n%m);
}

int main()
{  
   freopen("euclid2.in","r",stdin);
   freopen("euclid2.out","w",stdout);

    ll T;
    cin>>T;
    while(T--)
    {   ll n,m;
    	cin>>n,m;
    	cout<<gcdx(n,m);
    }

return 0;
}
