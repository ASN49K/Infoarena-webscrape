#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define lli long long int 
#define mod 1000000007
#define GIO ios_base::sync_with_stdio(0);cin.tie(0);


int main()
{ GIO;
    ll T;
    cin>>T;
    
    while(T--)
    {   ll n,m;
    	cin>>n>>m;
    	cout<<__gcd(n,m)<<"\n";
    	cout.flush();
    }

return 0;
}
