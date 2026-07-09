#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.first << ' ' << p.second << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define fi first
#define se second

const long double PI = acos(-1);

template<class T>
class LCS
{  
   const vector<T> a, b;
public:
   vector< vector< pair<T, char> > > dp;

   LCS(const vector<T>& a, const vector<T>& b) : a(a), b(b) 
   {
      for (int i = 0; i < a.size(); i++)
         dp.push_back(vector<pair<T, char>>(b.size()));
   }
   
   vector<T> run()
   {
      vector<T> ans;
      if (a.empty() || b.empty()) return ans;
      for (int i = 0; i < a.size(); i++)
         for (int j = 0; j < b.size(); j++)
         {
            int match = a[i] == b[j] ? (i > 0 && j > 0 ? dp[i - 1][j - 1].first + 1 : 1) : 0;
            int x = i > 0 ? dp[i - 1][j].first : 0;
            int y = j > 0 ? dp[i][j - 1].first : 0;
            int mx = max({match, x, y});
            dp[i][j] = {mx, mx == match && match != 0 ? 0 : (mx == x ? 1 : 2)};
         }
      int i = a.size() - 1;
      int j = b.size() - 1;
      while (i >= 0 && j >= 0)
      {
         if (dp[i][j].second == 0)
            ans.push_back(a[i]), i--, j--;
         else if (dp[i][j].second == 1)
            i--;
         else
            j--;
      }
      reverse(ans.begin(), ans.end());
      return ans;
   }
};

int main()
{
   ios::sync_with_stdio(false);

   freopen("cmlsc.in", "r", stdin);
   freopen("cmlsc.out", "w", stdout);
   
   vector<int> a, b;
   int n, m, x, y;
   cin >> n >> m;
   for (int i=0; i<n; i++) cin>>x, a.push_back(x);
   for (int i=0; i<m; i++) cin>>x, b.push_back(x);
   LCS<int> k(a, b);
   vector<int> v = k.run();
   cout << v.size() << '\n';
   for (auto i : v)
   {
      cout << i << " ";
   }
   return 0;
}