#include <iostream>
#include <fstream>
using namespace std;

ofstream fo("cmlsc.out");
ifstream fi("cmlsc.in");

int n,m;
int s1[1100];
int s2[1100];
int dp[1100][1100];
int raspuns[1100],nrelem;
int main()
{
    fi>>n>>m;
    for(int i=1; i<=n; i++)
        fi>>s1[i];
    for(int i=1; i<=m; i++)
        fi>>s2[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(s1[i]==s2[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j] =dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i][j-1];
            }
    fo<<dp[n][m]<<'\n';
    while(dp[n][m])
    {
        if(s1[n]==s2[m])
        {
            nrelem++;
            raspuns[nrelem]=s1[n];
            n--;
            m--;
        }
        else if(dp[n-1][m]>dp[n][m-1])
            n--;
        else
            m--;
    }



    for(int i=nrelem; i>0; i--)
        fo<<raspuns[i]<<" ";
    fi.close();
    fo.close();
    return 0;
}
