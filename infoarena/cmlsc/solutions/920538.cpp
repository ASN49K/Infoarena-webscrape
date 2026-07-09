#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[1030],y[1030],n,m,i,k,j,lcs[1300][1300],d[1030];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>x[i];
    for(i=1;i<=m;i++) f>>y[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(x[i]==y[j]) lcs[i][j]=1+lcs[i-1][j-1];
            else
                if(lcs[i-1][j]>lcs[i][j-1]) lcs[i][j]=lcs[i-1][j];
                else lcs[i][j]=lcs[i][j-1];
    g<<lcs[n][m]<<'\n';
    for(k=0, i=n, j=m; lcs[i][j]; )
        if(x[i]==y[j]) {d[k++]=x[i]; i--;j--;}
        else if(lcs[i][j]==lcs[i-1][j]) i--;
            else j--;
    for(i=k-1;i>=0;i--) g<<d[i]<<' ';
    f.close();
    g.close();
    return 0;
}
