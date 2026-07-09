#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int n,m,d;
vector<int> a;
vector<int> b;
vector<int> c;
int mat[1025][1025];
void cmlsc(){
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        if(a[i]==b[j]) mat[i][j]=1+mat[i-1][j-1];
        else if(mat[i-1][j]>mat[i][j-1]) mat[i][j]=mat[i-1][j];
        else mat[i][j]=mat[i][j-1];}}
void afis(int i,int j){
if(i>0&&j>0)
    if(a[i]==b[j]){
        c.push_back(a[i]);
        afis(i-1,j-1);}
    else if(mat[i-1][j]==mat[i][j]) afis(i-1,j);
    else if(mat[i][j-1]==mat[i][j]) afis(i,j-1);}
int main(){
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    a.resize(n+1);
    for(int i=1;i<=n;i++){f>>d;a[i]=d;}
    b.resize(m+1);
    for(int i=1;i<=m;i++){f>>d;b[i]=d;}
    cmlsc();
    afis(n,m);
    g<<c.size()<<'\n';
    for(int i=c.size();i>0;i--)g<<c[i-1]<<' ';
    f.close();
    g.close();
return 0;}
