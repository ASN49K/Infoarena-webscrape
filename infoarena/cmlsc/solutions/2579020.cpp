#include <bits/stdc++.h>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX=1025;
int A[NMAX],B[NMAX];
int N,M;

int Dp[NMAX][NMAX];

int st[NMAX];
void solve(){

    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
    {
        Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
        if(B[j]==A[i]) Dp[i][j]=1+Dp[i-1][j-1];
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j)
            cout<<Dp[i][j]<<" ";
        cout<<"\n";
    }


    for(int i=N,j=M; i>0 and j>0; )
    {
        if(B[j]==A[i])
            --i,--j, st[++st[0]]=A[i+1];
        else if(Dp[i-1][j]==Dp[i][j])
            --i;
        else --j;
    }

    fout<<Dp[N][M]<<"\n";
    for(int i=st[0]; i>0; --i)
        fout<<st[i]<<" ";
}


int main(){
    fin>>N>>M;
    for(int i=1;i<=N;++i)
        fin>>A[i];
    for(int i=1;i<=M;++i)
        fin>>B[i];
    solve();
}












