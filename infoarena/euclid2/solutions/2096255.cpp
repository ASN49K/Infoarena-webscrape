#include<bits/stdc++.h>

using namespace std;

int t,a,b;




int divc(int a, int b) {
	if (a==0) return b;
	return divc(a%b,a);
}

int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
	cin>>t;
	
	while (t--) {
		cin>>a>>b;
		if (a<b) swap(a,b);
		cout<<divc(a,b)<<'\n';
	}
	
	return 0;
}
