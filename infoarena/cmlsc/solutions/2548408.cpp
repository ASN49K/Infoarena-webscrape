#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int DIM = 1050;

int n,m,F[DIM],S[DIM],DP[DIM][DIM];

bool OK(int i, int j)
{
    if(i<1 || j<1 || i>n || j>m)
        return 0;
    return 1;
}

void Read()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
            fin>>F[i];
    for(int i=1;i<=m;i++)
            fin>>S[i];
}

void Solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(F[i]==S[j])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
        }
    }
    fout<<DP[n][m]<<'\n';
}

void Print(int l, int c)
{
    if(!OK(l,c))
        return;
    if(F[l]==S[c])
    {
        Print(l-1,c-1);
        fout<<F[l]<<" ";
    }
    else
    {
        int Max=max(DP[l-1][c],DP[l][c-1]);
        if(DP[l-1][c]==Max)
            Print(l-1,c);
        else
            Print(l,c-1);
    }
}

int main()
{
    Read();
    Solve();
    Print(n,m);
}
