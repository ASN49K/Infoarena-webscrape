#include<bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef vector < int >      vi;
typedef vector < ll >       vll;
typedef pair < int, int >   pii;
typedef pair < ll, ll >     pll;
typedef set<int>            sset;
typedef multiset<ll>        mset;

#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            a/gcd(a,b)*b
#define pb                  push_back
#define mp                  make_pair
#define endl                "\n"
#define optimize            ios::sync_with_stdio(0); cin.tie(0)

int  gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}

void solve()
{
  int a,b;cin>>a>>b;
  cout<<gcd(a,b)<<endl;
}

int main() {
   freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;while(t--)
    solve();

    return 0;
}


