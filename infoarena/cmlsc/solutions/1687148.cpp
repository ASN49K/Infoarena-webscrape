#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,i,j,x[1030],y[1030],c[1030][1030],b[1030],nr;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>x[i];
    for(j=1;j<=n;j++)
        f>>y[j];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(x[i]==y[j])
            c[i][j]=c[i-1][j-1]+1;
        else c[i][j]=max(c[i-1][j],c[i][j-1]);
    i=m;j=n;
    while(i)
        if (x[i]==y[j])
            {b[++nr]=x[i];i--;j--;}
        else if(c[i-1][j]<c[i][j-1])
            j--;
        else
            i--;
    g<<nr<<endl;
    for(i=nr;i;i--)
        g<<b[i]<<" ";
    return 0;
}
