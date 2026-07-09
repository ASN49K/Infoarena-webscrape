#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[1025][1025],a[1025],b[1025],sir[1025],i,j,m,nr,n;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
       {
           if(a[i]==b[j])
           {
               v[i][j]=1+v[i-1][j-1];
           }
           else
           v[i][j]=max(v[i-1][j],v[i][j-1]);
       }
       fout<<v[n][m]<<'\n';
       nr=v[n][m];i=n;j=m;
    while(nr!=0)
    {
        if(v[i-1][j]==nr)
            i--;
        else
            if(v[i][j-1]==nr)
                j--;
            else
            {
                sir[nr]=a[i];
                i--;
                j--;nr--;
            }

    }
    for(i=1;i<=v[n][m];i++)
        fout<<sir[i]<<" ";
    return 0;
}
