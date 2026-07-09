#pragma GCC optimize("O3")         //grandmixer//
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
using namespace std;

int m,n,a[1025],b[1025],rs[1026][1026];
vector<int>ans;

int main(){
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> m >> n;
    for(int i=1;i<=m;i++) fin >> a[i];
    for(int i=1;i<=n;i++) fin >> b[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i]==b[j]) rs[i][j]+=1;
            rs[i][j]+=max(rs[i-1][j],rs[i][j-1]);
        }
    }
    fout<<rs[m][n]<<endl;
    int g=m;
    int h=n;
    while(g!=1 && h!=1){
        if(rs[g-1][h]<rs[g][h]){ans.push_back(a[g]); g-=1; continue;}
        else if(rs[g][h-1]<rs[g][h]){ans.push_back(a[g]); h-=1; continue;}
        else g-=1;
    }
    for(int i=ans.size()-1;i>=0;i--){
        fout<<ans[i]<<' ';
    }

}
