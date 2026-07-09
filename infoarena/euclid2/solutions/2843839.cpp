#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forr(X) for(int i = 0; i<X; i++)
#pragma GCC optimize("Ofast")
#define F first
#define all(X) X.begin(), X.end()
#define S second
#define int ll
#define out(X) for(auto it: X){ for(auto ito : it)cout<<ito<<" "; cout<<endl;}
//#define MOD 1000000000000000031

int euclid(int a, int b){
	//cout<<a<<"  "<<b<<endl;
	if(a%b==0){
		return b;
	}
	return euclid(max(a%b, b), min(a%b, b));
	
}

void solve(){
	int a, b;
	cin>>a>>b;
	cout<<euclid(max(a, b), min(a, b))<<endl;
}

int32_t main(){
	//freopen("euclid2.in", "r", stdin);
	//freopen("euclid2.out", "w", stdout);
	int t;cin>>t;while(t--)
	solve();
}


