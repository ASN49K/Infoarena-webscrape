#include <fstream>
#define inf 50000000000ll
#include <cstring>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,x,y,a[1025],b[1025],d[1025][1025],t[1025][1025],sol[1025],i,j,k;
void reconst(int nr,int x,int y){
    if(d[x][y]!=0){
        if(nr==1)
            reconst(t[x-1][y-1],x-1,y-1);
        else if(nr==2)
            reconst(t[x-1][y],x-1,y);
        else
            reconst(t[x][y-1],x,y-1);
        if(a[x]==b[y])
            g<<a[x]<<' ';
    }
}
int main()
{   f>>n>>m;
    for(i=1;i<=n;i++)
        f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        if(a[i]==b[j]){
            t[i][j]=1;
            d[i][j]=d[i-1][j-1]+1;
        }
        else if(d[i-1][j]>d[i][j-1]){
            t[i][j]=2;
            d[i][j]=d[i-1][j];
        }
        else{
            t[i][j]=3;
            d[i][j]=d[i][j-1];
        }
    }
    g<<d[n][m]<<'\n';
    reconst(t[n][m],n,m);
    /*x=n;y=m;k=0;
    while(d[x][y]!=0){
        if(t[x][y]==1){
            if(a[x]==b[y])
                sol[++k]=a[x];
            x--;y--;
        }
        else if(t[x][y]==2){
            if(a[x]==b[y])
                sol[++k]=a[x];
            x--;
        }
        else{
            if(a[x]==b[y])
                sol[++k]=a[x];
            y--;
        }
    }
    for(i=k;i>=1;i--)
        g<<sol[i]<<' ';*/
    return '\0';
}
