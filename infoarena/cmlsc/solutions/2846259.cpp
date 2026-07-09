#include <bits/stdc++.h>
#define MAX 1024
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int maxim(int a,int b){
    if(a>b)return a;
    else return b;
}
int A[MAX],B[MAX],C[MAX][MAX],D[MAX],M,N,m;

int main()
{

    f>>M>>N;
    for(int i=1;i<=M;i++)
        f>>A[i];
    for(int i=1;i<=N;i++)
        f>>B[i];
    for(int i=1;i<=M;i++)
        for(int j=1;j<=N;j++)
            if(A[i]==B[j])
                C[i][j]=1+C[i-1][j-1];
            else
                C[i][j]=maxim(C[i-1][j],C[i][j-1]);
    int i=M,j=N;
    while(i){
        if(A[i]==B[j]){
            D[++m]=A[i];
            i--;
            j--;
        }else if(C[i-1][j]<C[i][j-1])
            j--;
        else
            i--;
    }
    g<<m<<'\n';
    for(int i=m;i>=1;i--)
        g<<D[i]<<" ";
    return 0;
}
