#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int i,j,x[257],y[257],a[257][257],n,m,sol[257];
void cmslc()
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(x[i]==y[j])
            {
                a[i][j]=1+a[i-1][j-1];
            }
            else
            {
                a[i][j]=max( a[i-1][j], a[i][j-1] );
            }
        }
    }
}
void afis()
{
    int l=a[n][m];
    fout<<l<<'\n';
    int i=n;j=m;
    while(l)
    {
        if(x[i]==y[j])
        {
            sol[l]=x[i];
            l--;
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]<a[i][j-1])j--;
            else i--;
        }
    }
    for(int k=1;k<=a[n][m];k++)
    {
        fout<<sol[k]<<" ";
    }
}
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>x[i];
    for(j=1;j<=m;j++)fin>>y[j];
    a[0][0]=0;
    cmslc();
    afis();
    return 0;
}
