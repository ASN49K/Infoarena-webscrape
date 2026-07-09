#include <stdio.h>
#define nmax 1024
#define max(a,b) (a>b)?a:b
using namespace std;
int n,m,a[nmax],b[nmax],c[nmax][nmax],i,j,sub[nmax],lmax;

int main()
{
    FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)fscanf(f,"%d",&a[i]);
    for(i=1;i<=m;i++)fscanf(f,"%d",&b[i]);



    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
    else c[i][j]=max(c[i-1][j],c[i][j-1]);
    lmax=c[n][m];
    i=n;j=m;
    while(c[i][j])
    if(a[i]==b[j]){sub[lmax--]=a[i];i--;j--;}
    else if(c[i][j]==c[i][j-1])j--;
    else i--;

    fprintf(g,"%d\n",c[n][m]);
    for(i=1;i<=c[n][m];i++)fprintf(g,"%d ",sub[i]);

    return 0;
}
