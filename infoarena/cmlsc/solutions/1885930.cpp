#include <bits/stdc++.h>

#define NMax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N,M;
int A[NMax],B[NMax];
int T[NMax][NMax];
int K,sol[NMax];

int main()
{
    fin>>N>>M;
    for(int i=1;i<=N;i++)
        fin>>A[i];
    for(int i=1;i<=M;i++)
        fin>>B[i];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(A[i]==B[j])
                T[i][j]=T[i-1][j-1]+1;
            else
                T[i][j]=max(T[i-1][j],T[i][j-1]);
    fout<<T[N][M]<<"\n";

    int i=N,j=M;
    while(i)
        if(A[i]==B[j])
        {
            sol[++K]=A[i];
            i--; j--;
        }
        else if(T[i-1][j]<T[i][j-1])
            j--;
        else
            i--;
    for(int i=K;i>0;i--)
        fout<<sol[i]<<" ";

    return 0;
}
