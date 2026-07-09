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
int n,m;
vi v1,v2;
int dp[N+5][N+5];

int sl[N+5];

int main(){
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    F0R(i,n){
        int foo;
        scanf("%d",&foo);
        v1.push_back(foo);
    }
    F0R(i,m){
        int foo;
        scanf("%d",&foo);
        v2.push_back(foo);
    }
    FOR(i,1,n+1)
        FOR(j,1,m+1){
            if(v1[i-1]==v2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    printf("%d\n",dp[n][m]);
    int p1=n-1,p2=m-1,nr=dp[n][m];
    while(nr>0){
        if(v1[p1]==v2[p2]){
            sl[nr-1]=v1[p1];
            nr--;
            p1--;
            p2--;
        }
        else{
            if(p1==0){
                p2--;
                continue;
            }
            if(p2==0){
                p1--;
                continue;
            }
            if(dp[p1-1][p2]==dp[p1][p2])
                p1--;
            else
                p2--;
        }
    }
    F0R(i,dp[n][m])
        printf("%d ",sl[i]);
    return 0;
}
