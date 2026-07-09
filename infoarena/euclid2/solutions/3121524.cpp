#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn=1e5+5;
 int gcd(int a,int b){
 	if(b==0) return a;
 	else return gcd(b,a%b);
 }
 int main(){
 	ifstream cin("euclid2.in");
 	ofstream cout("euclid2.out");
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		cout << gcd(a,b) << endl;
	}
 	return 0;
}
