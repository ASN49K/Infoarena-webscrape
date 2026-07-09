#include <bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0

using namespace std;

// infoarena: Algoritmul lui Euclid

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

int main(){
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);
	int n;
	cin >> n;
	int	ar[n];
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		ar[i] = gcd(x,y);
	}
	for(int i=0;i<n;i++){
		cout << ar[i] << '\n';
	}
	return 0;
}