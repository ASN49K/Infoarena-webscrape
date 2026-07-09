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
//#define int ll


ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");
#define cin fin
#define cout fout

int n, m;
int a[1025], b[1025];
int c[1025];

int dp[1025][1025];


//up-1
//up-left 2
//left 3
int dir[1025][1025];


int32_t main(){
INIT
cin>>n>>m;
for(int i=1; i<=n; i++){
    cin>>a[i];
}
for(int i=1; i<=m; i++){
    cin>>b[i];
}

for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
        if(a[i]==b[j]){
            dp[i][j]=dp[i-1][j-1]+1;
            dir[i][j]=2;
        }
        else{
            dp[i][j]=dp[i-1][j-1];
            dir[i][j]=2;
        }
        if(dp[i][j-1]>dp[i][j]){
            dp[i][j]=dp[i][j-1];
            dir[i][j]=3;
        }
        if(dp[i-1][j]>dp[i][j]){
            dp[i][j]=dp[i-1][j];
            dir[i][j]=1;
        }
    }
}


int i=n, j=m;
int ln=0;
while(i>0 && j>0){
    switch(dir[i][j]){
    case 1: i--; break;
    case 2: ln++; c[ln]=a[i]; i--; j--; break;
    case 3: j--; break;
    }
}
cout<<ln<<"\n";
for(int i=ln; i>=1; i--){
    cout<<c[i]<<" ";
}

return 0;
}
