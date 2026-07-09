#include <fstream>
#include <stack>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
stack<int>S;

int mat[1026][1026];
int v1[1026],v2[1026];
int n1,n2;

void recon(int i,int j){
    if(!mat[i][j]) return;
    else{
        if(mat[i][j]==mat[i-1][j] || mat[i][j]==mat[i][j-1]){
            if(mat[i-1][j]>mat[i][j-1]) recon(i-1,j);
            else recon(i,j-1);
        }
        else S.push(v1[i]),recon(i-1,j-1);
    }
}
int main()
{
    cin>>n1>>n2;
    for(int i=1;i<=n1;++i)
        cin>>v1[i];
    for(int i=1;i<=n2;++i)
        cin>>v2[i];
    
    for(int i=1;i<=n1;++i)
        for(int j=1;j<=n2;++j)
            if(v1[i]==v2[j]) mat[i][j]=1+mat[i-1][j-1];
            else mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
    
    recon(n1,n2);
    // cout<<mat[n1][n2];
    cout<<S.size()<<'\n';
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    
    // for(int i=1;i<=n1;++i,cout<<'\n')
    //     for(int j=1;j<=n2;++j) cout<<mat[i][j]<<" ";
    return 0;
}