#include<bits/stdc++.h>
using namespace std;

int euclid(int a, int b){
	//cout<<a<<"  "<<b<<endl;
	if(a%b==0){
		return b;
	}
	return euclid(max(a%b, b), min(a%b, b));
	
}

void solve(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", euclid(max(a, b), min(a, b)));
}

int32_t main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	int t;cin>>t;while(t--)
	solve();
}


