#include <stdio.h>
#include <stdlib.h>
#define mnmax 1024
using namespace std;
FILE *fin,*fout;
int a[mnmax+5],b[mnmax+5],m,n,sol[mnmax+5];
int maxv(int x,int y)
{
    return (x>y?x:y);
}
int main()
{
    fin=fopen("cmlsc.in","r");
    fout=fopen("cmlsc.out","w");
    fscanf(fin,"%d %d",&m,&n);
    int dp[m+5][n+5];
    for(int i=1;i<=m;i++)
        fscanf(fin,"%d",&a[i]);
    for(int i=1;i<=n;i++)
        fscanf(fin,"%d",&b[i]);
    for(int i=0;i<=n;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i]==b[j])
            dp[i][j]=dp[i-1][j-1]+1;
        else
            dp[i][j]=maxv(dp[i][j-1],dp[i-1][j]);
    }
    fprintf(fout,"%d\n",dp[m][n]);
    int i=m,j=n,k=1;
    while(i && j)
    {
        if(a[i]==b[j])
        {
            sol[k]=a[i];k++;--i;--j;
        }
        else
        {
            if(dp[i][j-1]>dp[i-1][j])
                --j;
            else
                --i;
        }
    }
    for(int i=dp[m][n];i>=1;i--)
        if(i==1)
            fprintf(fout,"%d",sol[i]);
        else
            fprintf(fout,"%d ",sol[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}
