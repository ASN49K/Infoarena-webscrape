#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll cmmdc(ll a, ll b){
	ll t;
	while(b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int main(){

	int t;
	ll a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << cmmdc(a, b) << "\n";
	}

	return 0;
}
