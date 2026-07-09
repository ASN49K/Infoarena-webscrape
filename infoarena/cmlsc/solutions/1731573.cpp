#include<fstream>


using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int a[1030][1030],b[1030],c[1030],z[1030],i,j,n,m,k;

int main()
{
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>b[i];
    for(j=1; j<=m; j++)
        f>>c[j];
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
    {
        if(b[i] == c[j])
            a[i][j] = a[i-1][j-1]+1;
        else
            a[i][j] = max(a[i-1][j], a[i][j-1]);
    }
    i=n;
    j=m;
    while(a[i][j])
    {
        while(a[i][j] == a[i-1][j])
            i--;
        while(a[i][j] == a[i][j-1])
            j--;
            k++;
        z[k]=b[i];
        i--;
        j--;
    }
    g<<a[n][m];
        g<<endl;
        for(i=k; i>=1; i--)
            g<<z[i]<<" ";
}
