#include <bits/stdc++.h>

using namespace std;
#define MAX (1<<10)+1

unsigned short dp[MAX][MAX];
unsigned short A[MAX], B[MAX];
unsigned short sol[MAX];

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    unsigned short M, N;

    fin>>M>>N;

    for(unsigned short i=1; i<=M; i++) fin>>A[i];
    for(unsigned short i=1; i<=N; i++) fin>>B[i];

    for(unsigned short i=1; i<=N; i++){
        for(unsigned short j=1; j<=M; j++){

            if(B[i]==A[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    fout<<dp[N][M]<<endl;

    unsigned short i=N, j=M;

    unsigned short k=0;

    while(i && j){
        if(B[i]==A[j]){
            sol[++k] = B[i];
            i--;    j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }

    for(; k>0; k--) fout<<sol[k]<<" ";
}
