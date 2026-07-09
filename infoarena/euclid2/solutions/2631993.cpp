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

int t,a,b;

int main() {
   freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    cin>>t;while(t--){
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    }

    return 0;
}


