#include <bits/stdc++.h>

#define NMAX 1029
using namespace std;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for (auto e : v) out << e << ' '; return out; }
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...); }
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dp[NMAX][NMAX];
int sol[NMAX];
int a[NMAX];
int b[NMAX];
int n, m;
int max1(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
void citire();
void dps();
int main()
{
	citire();
	dps();


	return 0;
}

void citire()
{
	int i, j;
	fin >> n >> m;
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= m; i++)
		fin >> b[i];

}
void dps()
{
	int i, j;
	// dp[i][j]
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	fout << dp[n][m] << '\n';

	i = n, j = m;
	int cnt = 0;
	while (i >= 1 && j >= 1) {
		if (a[i] == b[j]) {
			sol[++cnt] = a[i];
			i--, j--;
		}
		else
			if (dp[i][j - 1] < dp[i - 1][j])
				i--;
			else
				j--;
	}
	for (i = cnt; i >= 1; i--)
		fout << sol[i] << ' ';
}