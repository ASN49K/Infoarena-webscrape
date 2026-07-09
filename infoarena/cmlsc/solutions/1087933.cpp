#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define MAX 1026
int v[MAX],u[MAX],a[MAX][MAX],w[MAX];
int maxim(int a, int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int n=0,x,y,i,j;
    f>>x>>y;
    for(i=1;i<=x;i++)
        f>>v[i];
    for(i=1;i<=y;i++)
        f>>u[i];
    for(i=1;i<=x;i++)
        for(j=1;j<=y;j++)
            if(v[i]==u[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
    i=x;
    j=y;
    while(i>0 && j>0)
    {
        if(u[i]==v[j])
        {
            w[++n]=v[i];
            i--;
            j--;
        }
        else
            if(a[i-1][j]<a[i][j-1])
                j--;
            else
                i--;
    }
    g<<n<<"\n";
    for(i=n;i>=1;i--)
        g<<w[i]<<" ";
    return 0;
}
