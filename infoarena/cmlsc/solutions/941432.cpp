#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

short n,m,i,j,k;
short v[1025],w[1025],r[1025];
short M[1025][1025];

int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>v[i];
    for(i=1;i<=m;i++) f>>w[i];
    for(i=1;i<=n;i++) for(j=1;j<=m;j++)
        if(v[i]==w[j]) M[i][j]=1+M[i-1][j-1];
        else M[i][j]=M[i-1][j]>M[i][j-1]?M[i-1][j]:M[i][j-1];

    g<<M[n][m]<<"\n";

    i=n;j=m;
    while(k<M[n][m])
    {
        if(v[i]==w[j]) {r[++k]=v[i];i--;j--;}
        else
        {
            if(M[i-1][j]>M[i][j-1]) i--;
            else j--;
        }
    }

    for(i=k;i>=1;i--) g<<r[i]<<" ";
    g<<"\n";

    f.close();
    g.close();
    return 0;
}
