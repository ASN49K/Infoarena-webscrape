#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[10240],b[10240],c[10240][10240],d[10240],N,M,x,i,j;
int main()
{
    f>>N>>M;
    for(i=1; i<=N; i++)
        f>>a[i];
    for(j=1; j<=M; j++)
        f>>b[j];
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);

    }
    g<<c[N][M];
    g<<endl;
    while(i>0 && j>0)
    {
        if(a[i]==b[j])
        {
            x++;
            d[x]=a[i];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]>c[i][j-1])
                i--;
            else j--;
        }
    }

    for(i=x; i>=2; i--)
        g<<d[i]<<' ';
}
