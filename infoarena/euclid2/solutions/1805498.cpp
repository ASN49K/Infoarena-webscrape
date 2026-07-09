# include <bits/stdc++.h>
using namespace std;
int t, a, b;
int gcd(int a, int b){
	if (b==0) return a;
	return gcd(b, a % b);
}

int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>a>>b;
		cout<<gcd(a,b)<<'\n';
	}
	return 0;
}
