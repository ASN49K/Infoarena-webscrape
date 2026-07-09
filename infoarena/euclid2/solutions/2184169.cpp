#include<bits/stdc++.h>

using namespace std;

	
	
int t,a,b,r;


int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>t;
	
	while (t--) {
		cin>>a>>b; 
		cout<<__gcd(a,b)<<'\n';
	}
	
	return 0;
}
