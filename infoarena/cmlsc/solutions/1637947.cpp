#include <iostream>
#include <fstream>
#define MAX 1025
using namespace std;

short int n,m,a[MAX],b[MAX],dp[MAX][MAX];
ofstream g("cmlsc.out");
void citire()
{
    ifstream f("cmlsc.in");
    f>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];

}
void drum(int i, int j)
{
    if(i==0||j==0)
        return;
    if(a[i]==b[j]){
        drum(i-1,j-1);
        g<<a[i]<<" ";
    }
    else if(dp[i-1][j]>dp[i][j-1])
        drum(i-1,j);
    else
        drum(i,j-1);
}
int main()
{
    int i,j;
    citire();


    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1] + 1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    g<<dp[n][m]<<endl;
    //g<<sizeof(a)+sizeof(b)+sizeof(dp)<<endl;
    drum(n,m);
}
