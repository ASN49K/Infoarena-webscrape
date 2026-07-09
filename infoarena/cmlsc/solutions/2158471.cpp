#include <iostream>
#include <fstream>

using namespace std;
 const int MAX=1030;
int a[MAX],na,b[MAX],nb,dp[MAX][MAX],i,j,sol[MAX],x,y;
int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    in>>na>>nb;

    for(i=1;i<=na;i++) in>>a[i];
    for(i=1;i<=nb;i++) in>>b[i];

    for(i=1;i<=na;i++)
     for(j=1;j<=nb;j++)
        {
            if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j-1];

        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        }
        int x=na,y=nb;

        while(dp[x][y]>0)
        {
            if(a[x]==b[y])
            {
                sol[dp[x][y]]=a[x];
                x--;
                y--;
            }

            else
            {
                if(dp[x][y]==dp[x-1][y]) x--;
                else y--;
            }
        }

        out<<dp[na][nb]<<endl;

        for(i=1;i<=dp[na][nb];i++) out<<sol[i]<<" ";
    return 0;
}
