#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[1030], b[1030], d[1030][1030], i, j, o[1030], k;

int maxim(int x, int y){
    if(x<y)
        return y;
    return x;
}

int main(){
    f>>n>>m;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(j=1; j<=m; j++)
        f>>b[j];
    f.close();
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=maxim(d[i][j-1], d[i-1][j]);
    g<<d[n][m]<<"\n";
    i=n;
    j=m;
    while(d[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            o[++k]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
        }
    }
    for(i=k; i>0; i--)
        g<<o[i]<<' ';
    g<<"\n";
    g.close();
    return 0;
}
