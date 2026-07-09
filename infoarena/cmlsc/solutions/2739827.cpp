#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,a[1025],b[1025],dp[1025][1025],fromX[1025][1025],fromY[1025][1025],currentX,currentY,x,y,v[1025],k=1;
int main()
{
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                fromX[i][j]=i-1;
                fromY[i][j]=j-1;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    fromX[i][j]=i-1;
                    fromY[i][j]=j;
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    fromX[i][j]=i;
                    fromY[i][j]=j-1;
                }
            }
        }
    }
    out<<dp[n][m]<<"\n";
    currentX=n;
    currentY=m;
    while(currentX!=0 && currentY!=0)
    {
        x=currentX;
        y=currentY;
        currentX=fromX[x][y];
        currentY=fromY[x][y];
        if(fromX[x][y]==x-1 && fromY[x][y]==y-1)
            v[k++]=a[x];
    }
    for(int i=k-1;i>=1;i--)
        out<<v[i]<<" ";
    return 0;
}
