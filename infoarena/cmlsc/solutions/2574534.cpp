#include <fstream>
#define lim 1024

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m,i,j,dp[lim+5][lim+5];
int a[lim+5], b[lim+5];
int sol[lim+5], nr;

int main()
{
    in>>n>>m;
    for(i=1;i<=n;i++) in>>a[i];
    for(i=1;i<=m;i++) in>>b[i];

    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
        if(a[i] == b[j])
            dp[i][j] = dp[i-1][j-1] + 1;
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    //formare solutie
    i=n; j=m;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            sol[++nr] = a[i];
            i--;
            j--;
        }
        else if(dp[i][j-1] < dp[i-1][j]) i--;
        else j--;
    }

    //afisare solutie invers ca sa fie bine
    out<<nr<<'\n';
    for(i=nr; i>0; i--) out<<sol[i]<<' ';
    return 0;
}
