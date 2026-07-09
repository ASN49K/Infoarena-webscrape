#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(a == 0 or b == 0){
		return max(a, b);
	}
	
	if(a < b){
		swap(a, b);
	}
	
	return gcd(a % b, b);
}

void solve(){
	int a, b;
	cin >> a >> b;
	
	cout << gcd(a, b) << '\n';
}


int main(){
	int t = 1;
	cin >> t;
	
	while(t--){
		solve();
	}
}
