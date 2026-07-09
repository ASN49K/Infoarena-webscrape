#include<bits/stdc++.h>

using namespace std;

int n,a,b,r;

int gcd(int a,int b) {
	
	while (b!=0) {
		r = a%b;
		a=b;
		b=r;
	}
	return a;
}

int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>n;
	while(n--) {
		cin>>a>>b;
		cout<<__gcd(a,b)<<'\n';
	}


	return 0;
}

