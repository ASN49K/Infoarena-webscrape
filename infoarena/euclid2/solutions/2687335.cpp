#include <bits/stdc++.h>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

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
	fin >> t;
	while(t--){
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
	}

	return 0;
}
