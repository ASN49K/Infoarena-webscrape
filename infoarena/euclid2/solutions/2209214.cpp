#include <bits/stdc++.h>

#define rc(x) return cout<<x<<endl,0

using namespace std;

int t,a,b;

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
	cin >> t;
	for(int i=0; i<t; i++){
		cin >> a >> b;
		cout << gcd(a,b) << '\n';
	}
	return 0;
}