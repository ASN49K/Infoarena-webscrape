#include<bits/stdc++.h>
#define ll long long
#define sz size
#define pb push_back
#define er erase
#define in insert
#define fr first
#define sc second
#define mp make_pair
#define pi pair
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
#define rc(s) return cout<<s,0
#define int long long
using namespace std;

int m,n,a[1025],b[1025],rs[1026][1026];
vector<int>ans;

signed main(){
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> m >> n;
    for(int i=1;i<=m;i++) fin >> a[i];
    for(int i=1;i<=n;i++) fin >> b[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]) rs[i][j]+=1;
            rs[i][j]+=max(rs[i-1][j],rs[i][j-1]);
            if(rs[i][j]>min(i,j)) rs[i][j]=min(i,j);
        }
    }
    fout<<rs[m][n]<<endl;
    int g=m;
    int h=n;
    int k=rs[m][n];
    while(ans.size()!=rs[m][n]){
        if(rs[g-1][h]<rs[g][h] && g-1>=0 && h>0){ans.push_back(a[g]); g--; k--; continue;}
        else if(rs[g][h-1]<rs[g][h] && g>0 && h-1>=0){ans.push_back(b[h]); k--; h--; continue;}
        else if(g>=2)g--;
        else if(h>=2) h--;
        if(k==1 && m==1 && n==1) ans.pb(a[1]);
    }
    for(int i=rs[m][n]-1;i>=0;i--){
        fout<<ans[i]<<' ';
    }

}
