#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;
long long a, b;

long long gcd(long long a, long long b){
	return !b ? a : gcd(b, a % b);
}

int main(){
	in >> t;
	while(t--){
		in >> a >> b;
		out << gcd(a, b) << '\n';
	}
	return 0;
}
