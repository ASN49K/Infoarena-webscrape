#include<fstream>
using namespace std;
int n,m,a[1024],b[1024],c[1024],d[1024],x;
void fu(int i,int j,int ma)
{
    int j2=j;
    while(i<n&&j<m)
    {
        while(j<m&&a[i]!=b[j])
            j++;
        if(a[i]==b[j]&&j<m)
        {
            c[ma]=a[i];
            fu(i+1,j+1,ma+1);
        }
        i++;
        j=j2;
    }
    if(ma>x)
    {
        x=ma;
        for(int k=0;k<x;k++)
            d[k]=c[k];
        ma=0;
    }
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int i,j;
    f>>n>>m;
    for(i=0;i<n;i++)
        f>>a[i];
    for(j=0;j<m;j++)
        f>>b[j];
    fu(0,0,0);
    g<<x<<"\n";
    for(int k=0;k<x;k++)
        g<<d[k]<<" ";
    f.close();
    g.close();
    return 0;
}
