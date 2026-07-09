///Scutaru Matei
#include <fstream>
#include <iostream>
#include <queue>

std :: ifstream in("cmlsc.in");
std :: ofstream out("cmlsc.out");

const int DIM=1e3+50;
short x[DIM], y[DIM], dp[DIM][DIM], rez[DIM];


int main()
{
    int n, m;
    in>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        in>>x[i];
    }
    for(int i = 1; i <= m; i++)
    {
        in>>y[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i]==y[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=std :: max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i=n, j=m, lg=0;
    while(i>=1 && j>=1)
    {
        if(x[i]==y[j])
        {
            rez[++lg]=x[i];
            j--;
            i--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    out<<lg<<'\n';
    for(int i=lg; i>=1; i--)
        out<<rez[i]<<" ";
}
