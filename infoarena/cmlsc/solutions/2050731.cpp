#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main()
{
    int DP[100][100],A[1025],B[1025],n,m;

    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>A[i];

    for(int i=1; i<=m; i++)
        f>>B[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            if(A[i]==B[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i][j-1],DP[i-1][j]); }

    g<<DP[n][m]<<endl;

    int i=n,k=0,j=m,V[1025];
    while(i>0 && j>0 && DP[i][j]>0)
    {
        if(A[i]==B[j])
        {
            V[++k]=A[i];
            i--;
            j--;
        }
        else
        {
            if(DP[i-1][j]>DP[i][j-1])
                i--;
            else
                j--;
        }
    }

    for(i=k;i>=1;i--)
        g<<V[i]<<" ";

    return 0;
}
