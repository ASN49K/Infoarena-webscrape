#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short a[1025][1025];

int main()
{
    short n,m,*x,*y,*v,i,j,k;
    fin>>n>>m;
    x=new short[n+1];
    y=new short[m+1];
    for(i=1;i<=n;i++)
        fin>>x[i];
    for(i=1;i<=m;i++)
        fin>>y[i];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
            {
                if(a[i-1][j]>a[i][j-1])
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=a[i][j-1];
            }
        }
    }
    fout<<a[n][m]<<"\n";
    v=new short[a[n][m]];
    i=n;
    j=m;
    k=a[n][m]-1;
    while(i)
    {
        if (x[i] == y[j])
        {
            v[k]=x[i];
            i--;
            j--;
            k--;
        }
        else
        {
            if (a[i-1][j]<a[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(k=0;k<a[n][m];k++)
        fout<<v[k]<<" ";
}
