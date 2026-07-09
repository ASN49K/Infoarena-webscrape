#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int i,j,c,n,m,nr,a[1030],b[1030],d[1030][1030],sol[1030];
int maxim(int x, int y){
    if(x>y)
        return x;
    return y;
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i][j-1],d[i-1][j]);
    g<<d[n][m]<<'\n';
    i=n;j=m;
    while(d[i][j]!=0)
        if(a[i]==b[j]){
            sol[++nr]=a[i];
            i--;j--;
        }
        else{
            c=maxim(d[i][j-1],d[i-1][j]);
            if(c>d[i][j-1]){
                i--;
            }
            else
            {
                j--;
            }
        }
        for(i=nr;i>=1;i--)
            g<<sol[i]<<" ";
    return 0;
}
