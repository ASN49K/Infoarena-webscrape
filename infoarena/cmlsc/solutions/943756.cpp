#include <iostream>
#include <fstream>
using namespace std;
int i,j,n,m,a[1025],b[1025],c[1025][1025],maxi,x,d[1025],k;
int maxim(int x,int y)
{
    if(x>y)return x;
    return y;
}
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for(i=1;i<=n;i++)fin>>a[i];
    for(i=1;i<=m;i++)fin>>b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=maxim(c[i-1][j],c[i][j-1]);
            if(c[i][j]>maxi)maxi=c[i][j];
        }
    fout<<maxi<<'\n';
    for(i=n;i>=1;i--)
    {
        for(j=n;j>=1;j--)
        if(a[i]==b[j]&&c[i][j]==maxi)
        {
            d[maxi]=a[i];
            k++;
            maxi--;
            break;
        }
    }
    for(i=1;i<=k;i++)
    {
        fout<<d[i]<<" ";
    }
    fin.close();
    fout.close();
}
