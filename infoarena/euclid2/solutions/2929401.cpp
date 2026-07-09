#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
#define rloop(n) for(int i=1;i<=n;i++)
#define cloop(m) for(int j=1;j<=m;j++)
#define forr(n) for(int i=0;i<n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define mp make_pair
#define pb push_back
#define read_intv(a, n) for(int i = 0; i < n; i++){int elem; cin>>elem; a.pb(elem);}
#define read_intvii(a, n) for(int i = 0; i < n; i++){int fir, las; cin>>fir>>las; a.pb(mp(fir, las));}
#define read_matrix(a, n, m) rloop(n){cloop(m){cin>>a[i][j];}}
/*
#define cin fin
#define cout fout
ifstream fin
ofstream fout
*/

ifstream in("euclid2.in"); 
ofstream out("euclid2.out");
#define cin in
#define cout out

int dc(int a, int b){
	if(b==0){
		return a;
	}else{
		return dc(b, a%b);
	}
}

void solve(){
	int a, b;
	cin>>a>>b;
	cout<<dc(a,b)<<"\n";
}

int main(){
	int TESTCASES;
	cin>>TESTCASES;
	while(TESTCASES--){
		solve();
	}
	return 0;
}
