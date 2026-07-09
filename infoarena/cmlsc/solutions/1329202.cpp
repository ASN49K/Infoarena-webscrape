#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,c[1025][1025];
short a[1025],b[1025],x[1025];
void cit()
{
    f>>n>>m;
    int i;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    f.close();
}
void rez()
{
    int i,j,k=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j]) /*{*/c[i][j]=c[i-1][j-1]+1; /*k++; x[k]=a[i];}*/
            else c[i][j]=max(c[i][j-1],c[i-1][j]);
    g<<c[n][m];
}
int main()
{
    int i,j,k=0;
    cit();
    rez();
    g<<'\n';
    i=n;
    j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            k++;
            x[k]=a[i];
            i--;
            j--;
        }

        else
        {
            if(c[i][j-1]<c[i-1][j]) i--;
            else j--;
        }
    }

    for(i=k ; i>=1; i--) if(x[i]) g<<x[i]<<" ";
    g.close();
    return 0;
}
