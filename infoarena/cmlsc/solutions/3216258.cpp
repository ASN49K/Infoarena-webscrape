#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct custom_hash_pair {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

#define all(x) (x).begin(), (x).end()
#define allg(x) (x).begin(), (x).end(), greater<int>()
using ull = unsigned long long;
using ll =  long long;
using ld = double;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using si = set<int>;
using ssi = set<si>;
using sl = set<ll>;
using ssl = set<sl>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vs = vector<string>;
using vpi = vector<pii>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;
#define umap unordered_map
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define ff first
#define ss second
#define ar array
inline void yn(bool b)
{
    if(b==true)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
  inline void fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

ll Mod = 1e9+7;
inline bool hasbit(ll nr, ll pos)
{
    return (nr&(1ll<<pos));
}

const string TASK("cmlsc");
ifstream fin(TASK + ".in");
ofstream fout(TASK + ".out");
#define cin fin
#define cout fout
const ll Inf = 0x3f3f3f3f;
bool testCase = false;
const ll Nmax=1e3+30;

ll n,m;
ll v1[Nmax],v2[Nmax];
ll dp[Nmax][Nmax];
ll best[Nmax],poz=0;
void solve_testcase()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>v1[i];
  for(int i=1;i<=m;i++)
    cin>>v2[i];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(v1[i]==v2[j])
    dp[i][j] = dp[i-1][j-1] + 1;
    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
  int i=n,j=m;
  while(i>0&&j>0)
  {
    if(v1[i]==v2[j])
    {
      poz++;
      best[poz] = v1[i];
      i--;
      j--;
    }
    else if(dp[i-1][j] >= dp[i][j-1])i--;
    else j--;
  }
  cout<<poz<<'\n';
  for(i=poz;i>=1;i--)
    cout<<best[i]<<" ";
}

void pregenerate()
{

}

/// Check for interruption of input!!
/// a+b=a^b+2*(a&b)
int main() {
    fastio();
    pregenerate();
    ll t=1;
    if (testCase) cin >> t;
    while (t--)
    {   //cout<<t<<endl;
        solve_testcase();
    }
    return 0;
}
