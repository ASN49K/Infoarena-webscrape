#include<bits/stdc++.h>

#pragma gcc optimize("O3")

#define all(s) s.begin(),s.end()
#define rc(x) return cout<<x<<endl,0
#define forn(i,n) for(int i=0;i<int(n);i++)
#define len(a) (int) (a).size()

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

typedef long long ll;
typedef long double ld;

const int nmax=5e4+7;
const int mod=998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;

using namespace std;

int main()
{
  freopen("euclid2.in","r",stdin);
  freopen("euclid2.out","w",stdout);
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin>>t;
  while(t--) {
    int a,b;
    cin>>a>>b;
    cout<<__gcd(a,b)<<"\n";
  }
}
