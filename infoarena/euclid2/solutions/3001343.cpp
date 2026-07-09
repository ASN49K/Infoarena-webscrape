#include <bits/stdc++.h>
using ll=long long;
#define S second
#define F first
#define endl '\n'
#define spid ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod=1e9+7;
const double pi=3.14159265359;
const int maxn=200001;
using namespace std;

int t=1;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
	}
}

