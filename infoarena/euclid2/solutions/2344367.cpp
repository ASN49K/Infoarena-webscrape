#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	int t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<'\n';
	}
	return 0;
}
