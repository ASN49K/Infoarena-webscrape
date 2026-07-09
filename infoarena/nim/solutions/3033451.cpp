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

int t=1,n;

int main(){
	ifstream cin("nim.in");
	ofstream cout("nim.out");
	cin>>t;
	while(t--){
		cin>>n;
		int x;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>x;
			sum^=x;
		}
		if(!sum)cout<<"NU"<<endl;
		else cout<<"DA"<<endl;
	}
}

