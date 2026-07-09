#include<fstream>
#include<iostream>
using namespace std;
int main()
{
    ifstream f("cmlsc.in",ios::in);
    ofstream g("cmlsc.out",ios::out);
    int c[1025][1025],a[1025],b[1025],i,j,n,m,x=0,sub[1025];
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);}
    i=n;j=m;
    while(c[i][j])
    {
        while(c[i][j]==c[i-1][j])
            i--;
        while(c[i][j]==c[i][j-1])
            j--;
        x++;
        sub[x]=b[i];
        i--;
        j--;
    }
    g<<x<<"\n";
    for(i=x;i<=1;i--)
        g<<sub[i]<<" ";
    f.close();
    g.close();
}
