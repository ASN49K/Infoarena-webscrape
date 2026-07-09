#include <fstream>
using namespace std;
#define lmax 1026
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n,m,k;
int a[lmax],b[lmax],best[lmax][lmax];
int sir[lmax];

int maxim(int a, int b) {if(a>b) return a; return b;}

int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++) f>>a[i];
    for(int i=1;i<=m;i++) f>>b[i];
    f.close();
    for(int i=0;i<=n;i++) best[i][0]=0;
    for(int i=0;i<=m;i++) best[0][m]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]) best[i][j]=best[i-1][j-1]+1;
                else best[i][j]=maxim(best[i-1][j],best[i][j-1]);
    for(int i=n,j=m; i; )
        if(a[i]==b[j])
            sir[k++]=a[i],i--,j--;
        else if (best[i-1][j]<best[i][j-1])
            j--;
        else
            i--;
    g<<best[n][m]<<"\n";
    for(int i=k-1;i>=0;i--) g<<sir[i]<<" ";
    g<<"\n";
    g.close();
    return 0;
}
