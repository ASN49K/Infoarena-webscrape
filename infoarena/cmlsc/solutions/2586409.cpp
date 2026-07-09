#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int m, n;
int dp[1050][1050], a[1050], b[1050], sol[1050], traseu[1050][1050];
int main()
{
    fin>>m>>n;
    for(int i=1; i<=m; i++)
        fin>>a[i];
    for(int i=1; i<=n; i++)
        fin>>b[i];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(b[i]==a[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                traseu[i][j]=0;
            }
            else
            {
                 dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                 if(dp[i][j-1]<=dp[i-1][j])
                    traseu[i][j]=1;
                 else
                    traseu[i][j]=2;
            }

            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    fout<<dp[n][m]<<"\n";
    int pozx=n, pozy=m;
    while(pozx>0 && pozy>0)
    {
        if(traseu[pozx][pozy]==0)
        {
            sol[++sol[0]]=a[pozy];
            pozx--; pozy--;
        } else
        if(traseu[pozx][pozy]==1)
            pozx--;
        else pozy--;
    }
    /*
    while(pozx>0 && pozy>0)
    {
        if(b[pozx]==a[pozy])
        {
            sol[++sol[0]]=a[pozy];
            pozx--;
            pozy--;
        }else
        if(dp[pozx-1][pozy]>=dp[pozx][pozy-1])
            pozx--;
        else
            pozy--;
    }*/
    for(int i=sol[0]; i>=1; i--)
        fout<<sol[i]<<" ";
    return 0;
}
