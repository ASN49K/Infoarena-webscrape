#include<bits/stdc++.h>

using namespace std;

int main(){
	ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	int t,a,b;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b;
		if(max(a,b)%min(a,b)==0) cout<<min(a,b)<<"\n";
		else cout<<max(a,b)%min(a,b)<<"\n";
	}
	return 0;
}
