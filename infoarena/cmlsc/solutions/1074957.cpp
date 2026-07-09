# include <fstream>
using namespace std;
ifstream f("clmsc.in");
ofstream g("clmsc.out");
int n,m,k,b[1025],c[1025],a[1025][1025],v[1025];
void read()
{
    int i;
    f>>n>>m;
    for(i=1;i<=n;i++)
         f>>b[i];
    for(i=1;i<=m;i++)
         f>>c[i];
}
int pd()
{
    int i,j;
    for(i=1;i<=m;i++)
      for(j=1;j<=n;j++)
            {
             if(a[i][j-1]>a[i-1][j-1])
                 a[i][j]=a[i][j-1];
             else
               a[i][j]=a[i-1][j-1];
             a[i][j]+=(b[j]==c[i]);
            }
    return a[m][n];
}
void drum()
{
    int i,j;
    i=m;j=n;
    while(i>1||j>1)
           {
            if(a[i][j-1]>a[i-1][j-1])
                 {
                  if(a[i][j]==a[i][j-1]+1)
                       v[++k]=b[j];
                  j--;
                 }
            else
              {
               if(a[i][j]==a[i-1][j-1]+1)
                     v[++k]=b[j];
               i--;
               j--;
              }
           }
}
void write()
{
    int i;
    for(i=k;i;i--)
          g<<v[i]<<" ";
}
int main()
{
    read();
    g<<pd()<<'\n';
    drum();
    write();
    f.close();
    g.close();
    return 0;
}
