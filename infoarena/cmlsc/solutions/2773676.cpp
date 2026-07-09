#include <bits/stdc++.h>
#define nmax 1025
using namespace std;
string prob="cmlsc";
ifstream in(prob+".in");
ofstream out(prob+".out");
int d[nmax][nmax], a[nmax],b[nmax];
int main(){
    vector<int> res;
    int n,m;
    in>>n>>m;
    for(int i=1;i<=n;i++)in>>a[i];
    for(int i=1;i<=m;i++)in>>b[i];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[i][j]=(a[i]==b[j]?d[i-1][j-1]+1:max(d[i-1][j],d[i][j-1]));
    for(int i=n,j=m;i&&j;){
        if(a[i]==b[j]){
            res.push_back(a[i]);
            i--;
            j--;
        }else{
            if(d[i-1][j]<d[i][j-1]){
                j--;
            }else{
                i--;
            }
        }
    }
    out<<res.size()<<'\n';
    for(auto i=res.rbegin();i!=res.rend();i++)out<<*i<<' ';
}
