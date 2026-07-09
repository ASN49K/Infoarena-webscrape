#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int c[1026][1026],v[1026],i,j,m,n,nr,a[1026],b[1026];
void drum (int i, int j)
{
    if(i>0&&j>0)
        if(a[i]==b[j])
        {
            drum(i-1,j-1);
            g<<a[i]<<" ";
        }
        else  if(c[i-1][j]>c[i][j-1])
            drum(i-1,j);
        else drum(i,j-1);
}

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
                if(a[i]==b[j])
                {
                    c[i][j]=1+c[i-1][j-1];
                }
                else
                    if(c[i][j-1]>c[i-1][j])
                    c[i][j]=c[i][j-1];
                     else
                    c[i][j]=c[i-1][j];

        }
    g<<c[n][m]<<'\n';
  drum(n,m);
    return 0;
}
