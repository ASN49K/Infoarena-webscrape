#include <fstream>
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
int n,m,a[1030],b[1030],d[1030][1030],sol[1030];
int main()
{   f>>n>>m;
    for(int i=1;i<=n;i++) f>>a[i];
    for(int i=1;i<=m;i++) f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
                else d[i][j] = max(d[i-1][j],d[i][j-1]);
    int i=n,j=m,k=0;
    while(i && j)
        if(a[i]==b[j]) {sol[++k]=a[i]; i--; j--;}
            else if(d[i-1][j]>d[i][j-1]) i--; else j--;
    g<<k<<'\n';
    while(k) g<<sol[k--]<<' ';
    g.close(); return 0;
}
