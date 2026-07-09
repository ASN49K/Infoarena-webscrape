#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll n,a,b; 
int main() 
{ 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<__gcd(a,b)<<'\n';
	}			
    return 0; 
}
