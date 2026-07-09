#include <fstream>
#include <stack>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int mat[1026][1026],n,m,imax,jmax,lmax;
int v1[1026],v2[1026];
stack<int>Q;

void recon(int i,int j){
    if(!mat[i][j]) return;
    else{
        if(mat[i][j]==mat[i-1][j] || mat[i][j]==mat[i][j-1]){
            if(mat[i-1][j]>mat[i][j-1]) recon(i-1,j);
            else recon(i,j-1);
        }
        else Q.push(v1[i]),recon(i-1,j-1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>v1[i];
    for(int i=1;i<=m;++i) cin>>v2[i];
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(v1[i]==v2[j]) mat[i][j]=1+mat[i-1][j-1];
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
    cout<<mat[n][m]<<'\n';
    recon(n,m);
    // for(int i=1;i<=n;++i,cout<<'\n')
    //     for(int j=1;j<=m;++j) cout<<mat[i][j]<<" ";
    while(!Q.empty()){
        cout<<Q.top()<<" "; 
        Q.pop();
    }
    return 0;
}