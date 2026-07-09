#include <iostream>
#include<fstream>
#define N 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[N],b[N];
int dp[N][N];//dp[i][j]-cmlsc din primele i caractere din primul si j caractere din al 2lea
//rasp va fi in a[n][m]
int v[N];//pt afisare

void read()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;++i)
        fin>>a[i];
    for(j=1;j<=m;++j)
        fin>>b[j];
}

/*void print(int n,int m)
{
    if(n>=1&&m>=1)
        if(dp[n][m]==dp[n-1][m])print(n-1,m);
        else if(dp[n][m]==dp[n][m-1])print(n,m-1);
            else print(n-1,m-1);
    if(dp[n][m]==dp[n-1][m-1]+1)fout<<a[n]<<" ";
}*/

void print()
{
    int i=n,j=m,ct=0;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            v[++ct]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
                else j--;

    }
    for(i=ct;i>=1;--i)
        fout<<v[i]<<" ";


}

void solve()
{
    int i,j;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])//acelasi caracter
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

    fout<<dp[n][m]<<"\n";

    for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)cout<<dp[i][j]<<" ";
            cout<<"\n";
        }
    print();

}
int main()
{
    read();
    solve();

    return 0;
}
