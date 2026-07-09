#include <cstdio>
#include <fstream>
using namespace std;
int m,n,v[1024],x[1024],a[1024][1024],w[1024],igrec,ma,i,j;
int main(){
    freopen("cmlsc.in", "r", stdin);
    ofstream g ("cmlsc.out");
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d", &v[i]);
    for(i=1;i<=n;i++)
        scanf("%d", &x[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if (v[i] == x[j])
                a[i][j] = 1 + a[i-1][j-1];
            else{
                if(a[i-1][j]>a[i][j-1])ma=a[i-1][j];
            else ma=a[i][j-1];
                a[i][j] = ma;}
    for (i=m,j=n;i;)
        if (v[i]==x[j])
            w[++igrec]=v[i],--i,--j;
        else if (a[i-1][j] < a[i][j-1])--j;
        else
            --i;
    g<<igrec<<'\n';
    for (i=igrec;i;--i)
        g<<w[i]<<" ";
    return 0;}
