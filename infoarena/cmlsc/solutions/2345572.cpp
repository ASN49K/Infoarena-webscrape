#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ft first
#define sc second
#define bs binary_search
#define INF 10000000000
#define rc(x) return cout<<x<<endl,0
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
#define MAX 1234567
const ll mod = 1e9 + 7;

using namespace std;

int a,b,k, ans;
int dp[1030][1030];
int s1[1030], s2[1030];

int main(){_
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> a >> b;
	for(int i = 0; i<a; i++){
		cin >> s1[i];
	}
	for(int i = 0; i<b; i++){
		cin >> s2[i];
	}
	for(int j = 0; j<=a; j++){
		dp[0][j]=0; 
	}
	for(int i = 0; i<=b; i++){
		dp[i][0] = 0;
	}
	for(int i = 1; i<=a; i++){
		for(int j = 1; j<=b; j++){
			if(s1[i-1] == s2[j-1]) dp[i][j]=dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	ans = dp[a][b];
	k = ans;
	int s[k+1];
	cout << ans << '\n';	int i,j;
	while(ans != 0){
		if(ans != max(dp[a][b-1], dp[a-1][b])){
			s[ans] = s1[a-1];
			ans--;
			a--;
			b--;
		}
		else{
			if(max(dp[a-1][b], dp[a][b-1]) == dp[a-1][b]) a--;
			else b--;
		}
	}
	for(int i = 1; i<=k; i++){
		cout << s[i] << ' ';
	}
	cout << '\n';
}


