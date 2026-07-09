#include<stdio.h>
int m,n,a[1050], b[1050], x[1050][1050],i,j,vmax, c[1050],k;
char y[1050][1050],ch;

int main()
{
    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)scanf("%d",a+i);
    for(i=1;i<=n;i++)scanf("%d",b+i);
    for(i=1;i<=m;i++)
    {
        for (j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                x[i][j]=1+x[i-1][j-1];
                y[i][j]='\\';
            }
            else
            {
                vmax=x[i-1][j]; ch='|';
                if(x[i][j-1]>vmax){vmax=x[i][j-1];ch='-';}
                x[i][j]=vmax;
                y[i][j]=ch;
            }
        }
    }
    printf("%d\n",x[m][n]);
    i=m; j=n; k=x[m][n];
    while(i>=1 && j>=1)
    {
        if(y[i][j]=='\\'){c[k]=a[i];i--;j--;}
        else    if(y[i][j]=='-'){j--;}
                else i--;
    }
    for (i=1;i<=x[m][n];i++)printf("%d ",c[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
