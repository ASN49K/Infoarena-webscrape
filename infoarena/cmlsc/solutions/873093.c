#include<stdio.h>
int a[1025][1025],x[1024],y[1024];
char b[1025][1025];
int main()
{
    int m,n,z[1000],i,k,j;
    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++) scanf("%d",&x[i]);
    for(i=1;i<=n;i++) {scanf("%d",&y[i]);}
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
    printf("%d\n",k);
    for(i=k;i>=1;i--) printf("%d  ",z[i]);
    return 0;
}


