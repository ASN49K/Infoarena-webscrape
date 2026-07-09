#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1030;

int A[DIM],B[DIM],n,m,DP[DIM][DIM];

void Read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>A[i];
    for(int i=1;i<=m;i++)
        fin>>B[i];
}

void Print(int l, int c)
{
    if(A[l]==B[c])
    {
        if(DP[l][c]==1)
        {
            fout<<A[l]<<" ";
            return;
        }
        else
        {
            Print(l-1,c-1);
            fout<<A[l]<<" ";
        }
    }
    else
    {
        if(DP[l-1][c]==DP[l][c])
            Print(l-1,c);
        else if(DP[l][c-1]==DP[l][c])
            Print(l,c-1);
    }
}

void CMLSC()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
        }
    }
    fout<<DP[n][m]<<'\n';
}

int main()
{
    Read();
    CMLSC();
    Print(n,m);
}
