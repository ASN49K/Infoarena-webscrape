#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if (b==0){
		return a;
	} else {
		return gcd(b, a%b)
	}
}

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main(){

	int T,a,b;
	fin>>T;
	for(int i = 0; i < T; i++){
		cin>>a>>b;
		cout<<gcd(a,b);
	}
	
}
