#include<iostream>
#include<fstream>
using namespace std;
int a[1025][1025],x[1024],y[1024];
char b[1025][1025];
ifstream f;
ofstream g;
int main()
{
    int m,n,z[1000],i,k,j;
    f.open("cmlsc.in");
    g.open("cmlsc.out");
    f>>m>>n;
    for(i=1;i<=m;i++) f>>x[i];
    for(i=1;i<=n;i++) {f>>y[i];}
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(x[i]==y[j]) {a[i][j]=a[i-1][j-1]+1;b[i][j]='/';}
            else {
                a[i][j]=a[i][j-1];
                b[i][j]='-';
                if(a[i][j-1]<a[i-1][j]) {
                    a[i][j]=a[i-1][j];
                    b[i][j]='|';
                    }
            }
    i=m;j=n;k=0;
    while(i>0 && j>0)
    {
        if(b[i][j]=='/')
        {
            ++k;
            z[k]=x[i];
            --i;--j;
        }
        else
        {
            if(b[i][j]=='-') --j;
            else --i;
        }
    }
    g<<k<<endl;
    for(i=k;i>=1;i--) g<<z[i]<<" ";
    return 0;
}