#include <iostream>
#include <fstream>
#define NR 10000
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int dp[NR][NR],a[NR],b[NR],vAux[NR],m,n,iv=0;

void scrieMatrice(int a[],int b[],int m,int n)
{
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}

void citire(int a[],int n)
{
    for(int i=1; i<=n; i++)
        f>>a[i];
}

void getSubsit()
{
    int i=m,j=n;
    while(dp[i][j]!=0)
    {
        if(dp[i][j]!=dp[i-1][j-1])
        {
            vAux[++iv]=a[i];
            i--;
            j--;
        }
        else if(dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j]==dp[i][j-1]) j--;
    }
}

void getSubsitRecursiv(int i,int j)
{
    if(dp[i][j]!=0){
        if(dp[i][j]!=dp[i-1][j-1])
        {
            g<<a[i]<<" ";
            getSubsitRecursiv(i-1,j-1);
        }
        else if(dp[i][j]==dp[i-1][j]) getSubsitRecursiv(i-1,j);
        else if(dp[i][j]==dp[i][j-1]) getSubsitRecursiv(i,j-1);
}
}
int main()
{
    f>>m>>n;
    citire(a,m);
    citire(b,n);
    scrieMatrice(a,b,m,n);
    g<<dp[m][n];
    g<<"\n";
    getSubsit();
    for(int i=1; i<=iv; i++)
        g<<vAux[i]<<" ";
    //getSubsitRecursiv(m,n);


    return 0;
}
