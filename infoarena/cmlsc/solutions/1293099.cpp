#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],i,j,n,m,c[1025][1025],nr,x;
void citire(int n,int a[1025])
{
    int i=0;
    for(i=1;i<=n;i++)
        f>>a[i];
}
int maxim(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    f>>n>>m;
    citire(n,a);
    citire(m,b);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
           {
               c[i][j]=c[i-1][j-1]+1;
               nr++;
           }
        else
            c[i][j]=maxim(c[i-1][j],c[i][j-1]);
    }
    g<<nr<<"\n";
    i=n;
    j=m;
    while(c[i][j])
    {
        while(c[i][j]==c[i-1][j])
            i--;
        while(c[i][j]==c[i][j-1])
            j--;
            x++;
        a[x]=b[j];
        i--;
        j--;
    }
    for(i=x;i>=1;i--)
        g<<a[i]<<" ";
    return 0;
}
