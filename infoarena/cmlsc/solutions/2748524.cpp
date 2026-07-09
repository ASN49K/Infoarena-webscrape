#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using oset = tree<T, null_type, less<T>,
				  rb_tree_tag, tree_order_statistics_node_update>;

#ifdef Wi_TEST
	template<typename T1, typename T2>
	ostream& operator<<(ostream& out, pair<T1,T2> p) {
		out << "(" << p.first << ", " << p.second << ")";
		out.flush();
		return out;
	}
	#define deb(x) cout << #x << " = " << x << endl;
#else
	#define deb(x)
	#define cin fin
	#define cout fout
#endif

const long long MOD = 1e9+7;

int dp[1030][1030];

int main() {
	ios_base::sync_with_stdio(false);
	
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	
	int n, m, v[1030], w[1030], sir[1030], k = 0;
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
		cin >> v[i];
	for(int j = 1; j <= m; ++j)
		cin >> w[j];
		
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(v[i] == w[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int i = n, j = m;
	while(dp[i][j]) {
		if(v[i] == w[j]) {
			sir[k++] = v[i];
			--i; --j;
		}
		else if(dp[i-1][j] > dp[i][j-1])
			--i;
		else
			--j;
	}
	
	cout << k << '\n';
	while((k--) > 0)
		cout << sir[k] << ' ';
	return 0;
}

