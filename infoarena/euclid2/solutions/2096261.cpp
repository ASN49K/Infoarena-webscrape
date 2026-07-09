#include<bits/stdc++.h>

using namespace std;

int t,a,b;




int divc(int a, int b) {
	if (b==0) return a;
	return divc(b,a%b);
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
