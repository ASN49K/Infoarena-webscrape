#include<bits/stdc++.h>
using namespace std;	

int euclid(int a, int b) {
	if (b==0) {
		return a;
	}
	euclid(b,a%b);	
}
	
int main() {
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	int t;
	cin >> t;
	while(t--) {
		int a,b;
		cin >> a >> b;
		cout << euclid(a,b) << '\n';	
	}
	
}	
