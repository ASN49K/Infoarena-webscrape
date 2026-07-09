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

int main() {
	ios_base::sync_with_stdio(false);
	
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		int a, b;
		cin >> a >> b;
		cout << __gcd(a, b) << '\n';
	}
	
	return 0;
}

