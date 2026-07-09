#include <fstream>
using namespace std;
ifstream f("smlsc.in");
ofstream g("smlsc.out");
int n,m,bst=0,a[1030],b[1030],d[1030][1030],best[1030];
int i,j;
int maxim(int a,int b){if(a>b) return a;
                            else return b;
                      }
int main()
{   f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++)
        for(i=1;i<=n;i++)
            if(a[i]==b[j]) d[i][j]=1+d[i-1][j];
                else d[i][j]=maxim(d[i-1][j],d[i][j-1]);
    for(i=n, j=m; i>=1;)
        if(a[i]==b[j]) {best[++bst]=a[i]; --i; --j;}
            else {if(d[i-1][j]<d[i][j-1]) --j;
                   else --i;
                 }
    g<<bst<<'\n';
    for(i=bst;i>=1;--i) g<<best[i]<<" ";
    g<<'\n';
    return 0;
}
