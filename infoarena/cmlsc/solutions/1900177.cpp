#include <fstream>
using namespace std;
#define max(a, b) ((a>b)?a:b)
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, a[1025], b[1025], dp[1025][1025], s[1025], len=0;
void citire()
{

    int i;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
    fin.close();
}
void dinamica()
{
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    i=n; j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            s[++len]=a[i];
            i--; j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
            j--;
        else i--;
    }
}
int main()
{
    citire();
    dinamica();
    fout<<len<<endl;
    for(int i=len; i>=1; i--)
        fout<<s[i]<<' ';
    return 0;
}
