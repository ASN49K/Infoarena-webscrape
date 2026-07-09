#include <iostream>
#include <fstream>
#define nmax 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short v[nmax][nmax],A[nmax],B[nmax],C[nmax],n,m,k;

void read()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>A[i];
    for(int i=1;i<=m;i++)f>>B[i];
}
void solve()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(A[i]==B[j])
                v[i][j] = 1 + v[i-1][j-1];
            else v[i][j] = max(v[i][j-1],v[i-1][j]);
        }
    }
}
void back()
{
    int i=n,j=m;
    while(v[i][j])
    {
        if(A[i] == B[j])
            {
                C[++k] = A[i];
                j--;i--;
            }
        else if(v[i][j-1] < v[i-1][j])
            i--;
        else j--;
    }
}
void write()
{
    g<<v[n][m]<<endl;
    for(int i=k;i>=1;i--)g<<C[i]<<" ";
}
int main()
{
    read();
    solve();
    back();
    write();
    return 0;
}
