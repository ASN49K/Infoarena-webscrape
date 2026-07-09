
#include <fstream>
#include <stack>
#define MAX 1030
#define VMAX 260
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int n,m,A[MAX],B[MAX],Dp[MAX][MAX];
stack <short int> Stiva;
void Citire();
void Rezolv();
void Afisare();
int main(){
    Citire();
    Rezolv();
    Afisare();
    return 0;
}
void Citire(){
    int i,j,k=0,x;
    bool Fr[VMAX]={};
    fin>>n>>m;
    for(i=1;i<=n;++i){
        fin>>A[i];
        Fr[A[i]]=1;
    }
    k=m;
    m=0;
    for(i=1;i<=k;++i){
        fin>>x;
        if(Fr[x])B[++m]=x;
    }
}
void Rezolv(){
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(A[i]==B[j])
                Dp[i][j]=max(Dp[i-1][j-1],max(Dp[i-1][j],Dp[i][j-1]))+1;
            else
                Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);

        }
    }
}
void Afisare(){
    int i,j;
    i=n;
    j=m;
    while(i&&j){
        if(A[i]==B[j]){
            Stiva.push(A[i]);
            --i;--j;
        }else if(Dp[i][j-1]>Dp[i-1][j]) --j;
        else --i;
    }
    fout<<Stiva.size()<<'\n';
    while(!Stiva.empty()){
        fout<<Stiva.top()<<' ';
        Stiva.pop();
    }
    fout<<'\n';
}
