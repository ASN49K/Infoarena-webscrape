#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
#define cin fin
#define cout fout
int n,m;
vector<int>a,b;
int DP[1025][1025]={0};
vector<int>sol;
void lcs(){
    int i=n,j=m;
    while(i>0&&j>0){
        if(a[i]==b[j]){
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if(DP[i-1][j]>DP[i][j-1])i--;
        else j--;
    }
}
int main(){
    cin>>n>>m;
    a.push_back(0);
    b.push_back(0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);

    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    //i la a
    //j la b
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
        }
    }
    cout<<DP[n][m]<<'\n';
    lcs();
    for(auto i=sol.rbegin();i!=sol.rend();i++)
        cout<<*i<<' ';
}
