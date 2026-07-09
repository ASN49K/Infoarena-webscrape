#include <bits/stdc++.h>
using namespace std;
 
int i,n,a,b;
 
int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}
 
int main(){
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a>>b;
		cout<<gcd(a,b);
	}
    return 0;
}
