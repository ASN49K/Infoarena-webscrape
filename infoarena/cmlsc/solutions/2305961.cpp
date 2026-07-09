#include <fstream>
#include <queue>
#define MAX 1030
#define VMAX 260
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int n,m,A[MAX],B[MAX],Dp[MAX][MAX],maxi=1;
queue <short int> Que;
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
    int i,j,x;
    fin>>n>>m;
    for(i=1;i<=n;++i){
        fin>>A[i];
    }
    for(i=1;i<=m;++i){
        fin>>B[i];
    }
}
void Rezolv(){
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(A[i]==B[j]){
                Dp[i][j]=Dp[i-1][j-1]+1;
                if(Dp[i][j]==maxi){
                    Que.push(A[i]);
                    ++maxi;
                }
            }else Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);

        }
    }
}
void Afisare(){
    fout<<maxi-1<<'\n';
    while(!Que.empty()){
        fout<<Que.front()<<' ';
        Que.pop();
    }
    fout<<'\n';
}
