#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, a[1030][1030], v1[1030], v2[1030], k, sol[1030];
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(v1[i]==v2[j])
            a[i][j]=1+a[i-1][j-1];
        else a[i][j]=max(a[i-1][j],a[i][j-1]);
    }
    fout<<a[n][m]<<'\n';
    i=n,j=m;
    while(i>=1&&j>=1)
    {
        if(v1[i]==v2[j])
        {
            k++;
            sol[k]=v1[i];
            i--;
            j--;
        }
        else if(a[i-1][j]>a[i][j-1])
            i--;
        else j--;
    }
    for(i=k;i>=1;i--)
        fout<<sol[i]<<' ';
    return 0;
}
