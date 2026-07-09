//Trebuie cu matrice
//https://infoarena.ro/problema/cmlsc

/*
         { 0, daca suntem pe linia sau coloana 0
dp[i][j]={ max(dp[i-1][j], dp[i][j-1]), daca a[i]!=b[j]
         { dp[i-1][j-1]+1, daca a[i]==b[j]
*/
#include <iostream>
#include <fstream>

using namespace std;

int dp[1030][1030],n,m,a[1030],b[1030], sol[1030], k=0;

void dinpro ()
{
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++)
    {
        if (i==0 || j==0)
            dp[i][j]==0;
        else if (a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
}

void reconst (int x, int y, int &k)
{
    if (x==0||y==0)
        return;
    if (a[x]==b[y])
    {
        cout<<x<<" "<<y<<"\n";
        sol[k++]=a[x];
        reconst(x-1,y-1,k);
        return;
    }
    if (dp[x-1][y]>dp[x][y-1])
        {
            reconst(x-1,y,k);
            return;
        }
    reconst(x,y-1,k);
    return;
}

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    fin>>n>>m;
    for (int i=1;i<=n;i++)
        fin>>a[i];
    for (int i=1;i<=m;i++)
        fin>>b[i];
    dinpro();
    fout<<dp[n][m]<<"\n";
    reconst(n,m,k);
    for (int i=k-1;i>=0;i--)
        fout<<sol[i]<<" ";
    return 0;
}
