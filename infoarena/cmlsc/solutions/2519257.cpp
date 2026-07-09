#include <fstream>
using namespace std;
int a[1025], b[1025], c[1025];
int main()
{
 ifstream fin("cmlsc.in");
 ofstream fout("cmlsc.out");
    int n,m,i,j,p=0;
    fin>>n>>m;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for (j=1; j<=m; j++)
        fin>>b[j];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        if(a[i]==b[j])
        c[++p]=a[i];
    fout<<p<<endl;
    for (i=1; i<=p; i++)
       fout<<c[i]<<" ";
}
