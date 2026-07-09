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

int t, n, m, k, a[2000], b[1030];
int dp[1025][1025], dir[1025][1025];


ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");
#define cin fin
#define cout fout



int32_t main(){
INIT
cin>>n>>m;
for(int i=1; i<=n; i++){cin>>a[i];}
for(int i=1; i<=m; i++){cin>>b[i];}


for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        if( dp[i-1][j-1]>=max(dp[i-1][j], dp[i][j-1])  ){
            dir[i][j]=2; dp[i][j]=dp[i-1][j-1]+((a[i]==b[j])?1:0);
        }
        else{

            if(dp[i-1][j]>=dp[i][j-1]){
                dir[i][j]=1; dp[i][j]=dp[i-1][j]+((a[i]==b[j])?1:0);
            }
            else{
                dir[i][j]=3; dp[i][j]=dp[i-1][j]+((a[i]==b[j])?1:0);
            }

        }
    }
}


int x=m, y=n;
cout<<dp[y][x]<<"\n";
vector<int> res;
while(x>0 && y>0){
    int d=dir[y][x];

    if(d==1){
        if(dp[y-1][x]<dp[y][x] ){
            res.pb(a[y]);
        }
        y--;
    }

    if(d==2){
        if(dp[y-1][x-1]<dp[y][x]){
            res.pb(a[y]);
        }
        x--; y--;
    }
    if(d==3){
        if(dp[y][x-1]<dp[y][x]){
            res.pb(a[y]);
        }
        x--;
    }
}

for(int i=res.size()-1; i>=0; i--){
    cout<<res[i]<<" ";
}






return 0;
}

