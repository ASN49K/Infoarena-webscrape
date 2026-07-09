#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
short n,m,x[1025],y[1025],a[1025][1025],sol[1025];
void citire()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int j=1;j<=m;j++)
        fin>>y[j];
}
void cmlsc()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j])a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
}
void afis()
{
    int l=a[n][m];
    fout<<l<<'\n';
    int i=n, j=m;
    while(l!=0)
    {
        if(x[i]==y[j])
        {
            sol[l]=x[i];
            l--;j--;i--;
        }
        else if(a[i-1][j]<a[i][j-1]) j--;
             else i--;
    }
    for(i=1;i<=a[n][m];i++)
        fout<<sol[i]<<" ";
}
int main()
{
    citire();
    cmlsc();
    afis();
    return 0;
}
