#include<bits/stdc++.h>

using namespace std;

int n;

int gcd(int a,int b) {
	if (b==0) {
		return a;
	} else {
		return gcd(b, a%b);
	}
}

int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	while(n--) {
		int a,b; cin>>a>>b;
		if (a<b) swap(a,b);
		cout<<gcd(a,b)<<'\n';
	}


	return 0;
}

