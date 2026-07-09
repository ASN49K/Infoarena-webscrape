#include <bits/stdc++.h>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX=1025;
int A[NMAX],B[NMAX];
int N,M;

int Dp[NMAX][NMAX];

void solve(){

    for(int i=1;i<=N;++i)
        for(int j=1;j<=M;++j)
    {
        Dp[i][j]=max(Dp[i-1][j],Dp[i][j-1]);
        if(B[j]==A[i]) Dp[i][j]=max(1+Dp[i-1][j-1],Dp[i][j]);
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j)
            cout<<Dp[i][j]<<" ";
        cout<<"\n";
    }

    vector <int> st;
    for(int i=N,j=M; i>0 and j>0; )
    {
        if(Dp[i][j]==Dp[i-1][j]){
            --i;
        }
        else if(Dp[i][j]==Dp[i][j-1]){
            --j;
        }
        else {
            if(Dp[i][j-1]>Dp[i-1][j])--j;
            else --i;
            st.push_back(B[j]);
        }
    }

    fout<<Dp[N][M]<<"\n";
    reverse(st.begin(),st.end());
    for(int i=0;i<st.size();++i)
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












