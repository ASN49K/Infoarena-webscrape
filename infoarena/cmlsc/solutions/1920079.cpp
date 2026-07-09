#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int S1[1030],S2[1030];
int DP[1030][1030];
int n,m;
vector<int> R;

void read(){
    in>>n>>m;
    for(int i=1;i<=n;i++){
        in>>S1[i];
    }
    for(int j=1;j<=m;j++){
        in>>S2[j];
    }
}
void reconst(int x, int y){
    if(S1[x]==S2[y]){
        R.push_back(S1[x]);
        if(x>1&&y>1)reconst(x-1,y-1);
    }
    else if(DP[x-1][y]>DP[x][y-1]){
        if(x>1)reconst(x-1,y);
    }
    else if(y>1){
        reconst(x,y-1);
    }
}
void solve(){
    int rmax=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(S1[i]==S2[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
        }
    }
    out<<DP[n][m]<<"\n";
    reconst(n,m);
    for(auto it=R.rbegin();it!=R.rend();it++){
        out<<*it<<" ";
    }
}
int main(){
    read();
    solve();
    return 0;
}
