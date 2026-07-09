#include<fstream>
#define dim 1030
using namespace std;
int a[dim][dim],b[dim],c[dim],x,rez[dim],n,m;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>b[i];
    for(int i=1;i<=m;i++)
        f>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(b[i]==c[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i][j-1],a[i-1][j]);
        }
        int i=n;
        int j=m;
        while(a[i][j])
        {
            while(a[i][j]==a[i-1][j])
                i--;
            while(a[i][j]==a[i][j-1])
                j--;
            x++;
            rez
            [x]=b[i];
            i--;
            j--;
        }
        g<<a[n][m]<<"\n";
        for(int i=x;i>=1;i--)
            g<<rez[i]<<" ";
}
