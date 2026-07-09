#include <fstream>
#define MAX 1500
using namespace std;
int lcs[MAX][MAX],unde[MAX][MAX],a[MAX],b[MAX];
int n,m;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
void citire();
int main()
{
    int i,j;
    citire();
    for(i=n; i>=1; i--)
        for(j=m; j>=1; j--)
            if(a[i]==b[j])
            {
                lcs[i][j]=1+lcs[i+1][j+1];
                unde[i][j]=1;
            }
            else if(lcs[i][j+1]>lcs[i+1][j])
            {
                lcs[i][j]=lcs[i][j+1];
                unde[i][j]=2;
            }
            else
            {
                lcs[i][j]=lcs[i+1][j];
                unde[i][j]=3;
            }
    fout<<lcs[1][1]<<'\n';
    i=1;
    j=1;
    while(i<=n&&j<=m)
    {
        if(unde[i][j]==1)
            {fout<<a[i]<<' ';
             i++;
             j++;
            }
        else if(unde[i][j]==2)
            j++;
        else
            i++;
    }
    return 0;
}
void citire()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        fin>>a[i];
    for(i=1; i<=m; i++)
        fin>>b[i];
}
