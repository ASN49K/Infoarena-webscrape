#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int D[1025][1025];

int main()
{
    int N,M;
    f>>N>>M;
    vector<int> A(N+1),B(M+1),S;
    for(int i=1;i<=N;i++) f>>A[i];
    for(int i=1;i<=M;i++) f>>B[i];

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            if(A[i]==B[j])
                 D[i][j]=1+D[i-1][j-1];
            else D[i][j]=max(D[i-1][j],D[i][j-1]);
    for(int i=N,j=M;i>0;)
        if(A[i]==B[j]) S.push_back(A[i]),i--,j--;
        else if (D[i-1][j]<D[i][j-1])
            j--;
        else
            i--;
    g<<S.size()<<'\n';
    for(int i=S.size()-1;i>=0;i--)
        g<<S[i]<<' ';
    return 0;
}
