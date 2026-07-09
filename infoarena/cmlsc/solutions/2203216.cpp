#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int N=1024;
int dp[N+5][N+5],n,m,v1[N+5],v2[N+5];
vi sl;
int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    FOR(i,1,n+1)
        scanf("%d",&v1[i]);
    FOR(i,1,m+1)
        scanf("%d",&v2[i]);
    FOR(i,1,n+1)
       FOR(j,1,m+1)
            if(v1[i]==v2[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    printf("%d\n",dp[n][m]);
    int pn=n,pm=m;
    while(pn and pm){
        if(v1[pn]==v2[pm]){
            sl.push_back(v1[pn]);
            pn--;
            pm--;
            continue;
        }
        if(dp[pn-1][pm]==dp[pn][pm])
            pn--;
        else
            pm--;
    }
    F0Rd(i,sl.size())
        printf("%d ",sl[i]);
    return 0;
}
