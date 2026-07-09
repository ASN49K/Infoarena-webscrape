#include <iostream>
#include <fstream>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int maxi(int a, int b)
{
    int maxz;

    if (a>b) maxz=a;
    else maxz=b;;
    return maxz;
}
const int MAX=1030;
int a[MAX], na, b[MAX], nb, dp[MAX][MAX], sol[MAX];

int main()
{
    in>>na;
    in>>nb;
    for(int i=1; i<=na; ++i) in>>a[i];
    for(int j=1; j<=nb; ++j) in>>b[j];
    for(int i=1; i<=na; ++i)
        for(int j=1; j<=nb; ++j)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=maxi(dp[i][j-1],dp[i-1][j]);
        }
    int x=na;
    int y=nb;
    while(dp[x][y]>0)
    {
        if(a[x]==b[y])
        {
            sol[dp[x][y]]=a[x];
            --x;
            --y;

        }
        else if(dp[x][y]==dp[x-1][y])
            --x;
        else --y;
    }
    out<<dp[na][nb]<<'\n';
    for(int i=1; i<=dp[na][nb]; ++i)
        out<<sol[i]<<" ";
    return 0;
}
