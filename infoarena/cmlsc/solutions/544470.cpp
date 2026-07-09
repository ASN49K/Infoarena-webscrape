#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int max(int a,int b){
if(a>b)return a;
return b;}
int main(){
    vector<vector<int> > mat;
    vector<int> vn,vm;
    vector<int> sol;
    int i,j;
    int n,m,d;
    ifstream f("cmlsc.in");
    f>>n>>m;
    for(i=0;i<n;i++){f>>d;vn.push_back(d);}
    for(i=0;i<m;i++){f>>d;vm.push_back(d);}
    mat.resize(n+1);for(int i=0;i<=n;i++)mat[i].resize(m+1,0);
    sol.resize(0);

    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(vn[i-1]==vm[j-1])mat[i][j]=mat[i-1][j-1]+1;
    else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);

    i=n-1;j=m-1;
    while(i>=0&&j>=0){
        if(vn[i]==vm[j]){sol.push_back(vn[i]);i--;j--;}
        else if(mat[i][j+1]<mat[i+1][j])j--;
        else i--;}

    ofstream g("cmlsc.out");
    g<<sol.size()<<'\n';
    for(i=sol.size()-1;i>=0;i--)g<<sol[i]<<' ';cout<<endl;
return 0;}
