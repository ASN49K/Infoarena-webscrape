#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");

int n,a,b;

int gcd(int val1,int val2){
	int x;
	while(val2){
		x=val2;
		val2=val1%val2;
		val1=x;
	}
	return val1;
}

int main(){
	fin>>n;
	for(int i=1;i<=n;i++){
		fin>>a>>b;
		fout<<gcd(a,b)<<'\n';
	}
	return 0;
}

