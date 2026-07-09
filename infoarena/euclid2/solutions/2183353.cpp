#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream in("tst.in");
ofstream out("tst.out");	

ll x, y;
int t;

ll gcd(ll a, ll b){
	return (!b ? a : gcd(b, a % b));
}

int main(){
	in >> t;
	while(in >> x >> y)
		out << gcd(x, y) << '\n';
	return 0;
}
