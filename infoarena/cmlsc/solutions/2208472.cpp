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
            if(a[i]==b[j]) rs[i][j]=rs[i-1][j-1]+1;
            else rs[i][j]=max(rs[i-1][j],rs[i][j-1]);
        }
    }
    int g=m;
    int h=n;
    int k=rs[m][n];
    int i=m;
    int j=n;
    while(k){
        if(a[i]==b[j]){
            ans.push_back(a[i]);
            i--;
            j--;
            k--;
        }
        else{
            if(rs[i][j-1]>=rs[i-1][j]) j--;
            else i--;
        }
    }
    fout<<rs[m][n]<<endl;
    for(int i=rs[m][n]-1;i>=0;i--){
        fout<<ans[i]<<' ';
    }

}
