#include<stdio.h>
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");
int n,m,a[1025],b[1025],dp[1025][1025],subsir[1025],lh;
int main()
{int i,j;
fscanf(f,"%d %d",&n,&m);
for(i=1;i<=n;i++)
{
    fscanf(f,"%d",&a[i]);
}
for(i=1;i<=m;i++)
{
    fscanf(f,"%d",&b[i]);
}
for(i=1;i<=n;i++)
{
    for(j=1;j<=m;j++)
    {
        if(a[i]==b[j])
        {
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
            {
                dp[i][j]=dp[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
}
i=n;j=m;
while(i)
{
    if(a[i]==b[j])
    {
        subsir[++lh]=a[i];i--;j--;
    }
    else
    {
        if(dp[i][j-1]>dp[i-1][j-1])
        {
            j--;
        }
        else
        {
            i--;
        }
    }
}
fprintf(g,"%d\n",lh);
for(i=lh;i>=1;i--)
{
    fprintf(g,"%d ",subsir[i]);
}
fclose(f);
fclose(g);
return 0;
}
