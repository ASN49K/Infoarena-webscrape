#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1025],b[1025],i,j,x[1025][1025],y,z[1025],k;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
    {
        f>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        f>>b[i];
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                x[i][j]=x[i-1][j-1]+1;
            }
            else
            {
                if(x[i-1][j]>x[i][j-1])
                    x[i][j]=x[i-1][j];
                else x[i][j]=x[i][j-1];
            }
        }
    }
    i=m;j=n;k=x[m][n];
    while(i!=0 && j!=0)
    {
      if(a[i]==b[j])
      {
        z[k]=a[i]; i--;j--;k--;
      }
      else
      {
         if(x[i-1][j]==x[i][j])i--;
         else j--;
      }
    }
    for(i=1;i<=x[m][n];i++)
    {
       g<<z[i]<<" ";
    }
    f.close();
    g.close();
    return 0;
}
