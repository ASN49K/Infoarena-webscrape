#include<stdio.h>
int a[1025][1025];
char b[1025][1025];
int main()
{
    int m,n,x[1024],y[1024],z[1000],i,k,j;
    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++) scanf("%d",&x[i]);
    for(i=1;i<=n;i++) scanf("%d",&y[i]);
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
    printf("%d\n",&a[m][n]);
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
    for(i=k;i>=1;i--) printf("%d ",&x[k]);
    return 0;
}


