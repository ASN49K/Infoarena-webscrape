#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short int m, n, a[1025], b[1025], dp[1025][1025], sol[1025], len=0;
void citire()
{
    int i;
    fin>>m>>n;
    for(i=1; i<=m; i++)
        fin>>a[i];
    for(i=1; i<=n; i++)
        fin>>b[i];
    fin.close();
}
void dinamica()
{
    int i, j;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    i=m; j=n;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol[++len]=a[i];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else j--;
    }
}
void afisare()
{
    int i;
    fout<<len<<'\n';
    for(i=len; i>=1; i--)
        fout<<sol[i]<<' ';
    fout<<'\n';
    fout.close();
}
int main()
{
    citire();
    dinamica();
    afisare();
    return 0;
}
