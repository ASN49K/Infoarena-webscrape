#include<fstream>
#include<iostream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,a[1025],b[1025],d[1025][1025],v[1025],dim;
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
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    dim=0;
    i=n;
    j=m;
    while(i>0 && j>0)
        if(a[i]==b[j])
        {
            dim++;
            v[dim]=a[i];
            i--;
            j--;
        }
        else
            if(d[i-1][j]<d[i][j-1])
                j--;
            else
                i--;
    g<<dim<<"\n";
    while(dim!=0)
    {
        g<<v[dim]<<" ";
        dim--;
    }
    f.close();
    g.close();
    return 0;
}

