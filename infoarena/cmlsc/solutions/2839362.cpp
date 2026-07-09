#include<bits/stdc++.h>
using namespace std;
#define INIT  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define ll long long
#define pii pair<int, int>
#define count_bits __builtin_popcount
#define int ll



ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");
#define cin fin
#define cout fout



int n, m, a[2000], b[2000];


int dp[1025][1025];
int dir[1025][1025];

void cmlsc(){


for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        if(a[i]==b[j]){
            int mx=max( dp[i-1][j-1]+1, max(dp[i-1][j], dp[i][j-1]) );
            dp[i][j]=mx;
            if( (dp[i-1][j-1]+1)==mx ){
                dir[i][j]=2;
            }
            else{
                if(dp[i-1][j]==mx ){
                    dir[i][j]=3;
                }
                else{
                    dir[i][j]=1;
                }
            }
        }
        else{
            int mx=max( dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]) );
            dp[i][j]=mx;
            if( (dp[i-1][j-1])==mx ){
                dir[i][j]=2;
            }
            else{
                if(dp[i-1][j]==mx ){
                    dir[i][j]=3;
                }
                else{
                    dir[i][j]=1;
                }
            }
        }
    }
}




vector<int> v;


pii pr={n, m};

while( (pr.sc>0) && (pr.ft>0) ){
    if(dir[pr.ft][pr.sc]==1){
        pr.sc--;
    }
    if(dir[pr.ft][pr.sc]==2){
        if(dp[pr.ft][pr.sc]==(dp[pr.ft-1][pr.sc-1]+1) ){
            v.pb(a[pr.ft]);
        }
        pr.ft--; pr.sc--;
    }
    if(dir[pr.ft][pr.sc]==3){
        pr.ft--;
    }
}
reverse(v.begin(), v.end());

cout<<v.size()<<"\n";
for(auto x:v){
    cout<<x<<" ";
}

}






int32_t main(){
INIT
cin>>n>>m;
for(int i=1; i<=n; i++){
    cin>>a[i];
}
for(int i=1; i<=m; i++){
    cin>>b[i];
}

cmlsc();



return 0;
}
