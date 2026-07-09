#include <iostream>
#define Nmax 1025
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,A[Nmax],B[Nmax];
int DP[Nmax][Nmax];
int sol[Nmax],nr;
void read()
{
    int i;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>A[i];
    for(i=1;i<=n;i++)
        fin>>B[i];

}

void solve()
{
    int i,j;

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(A[i]==B[j])
                 DP[i][j]=DP[i-1][j-1]+1;

            else
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);

}

void write()
{
    int i,j;
    for(i=m;i>0;i--)
        for(j=n;j>0;j--)
        if(A[i]==B[j])
            sol[++nr]=A[i],i--,j--;
        else
            if(DP[i-1][j]<DP[i][j-1]) j--;
            else i--;

    fout<<nr<<"\n";
        for(int k=nr;k>=1;k--)
            fout<<sol[k]<<" ";


}
int main()
{
    read();
    solve();
    write();
    return 0;
}
