#include <stdio.h>

int dp[1030][1030],r[1030][1030],n,m,i,j,t[1030],s[1030],p[1030];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

 scanf("%d %d",&n,&m);
 n++,m++;
 for (i=1;i<n;i++)
    scanf("%d",t+i);
 for (i=1;i<m;i++)
    scanf("%d",s+i);
 for (i=1;i<n;i++)
    for (j=1;j<m;j++)
      if (t[i]==s[j])
      {
        dp[i][j]=dp[i-1][j-1]+1;
        r[i][j]=i*1000+j;
      } else
       {
         if (dp[i-1][j]>dp[i][j-1])
         {
             dp[i][j]=dp[i-1][j];
             r[i][j]=(i-1)*1000+j;
         } else
         {
             dp[i][j]=dp[i][j-1];
             r[i][j]=i*1000+j-1;
         }
       }


    printf("%d\n",dp[n-1][m-1]);
    int k=dp[i=n-1][j=m-1];
    while (k)
    {
      if (t[i]==s[j])
      {
          p[k]=t[i];
          k--;i--;j--;
      } else
        i=r[i][j],j=i % 1000,i/=1000;
    }

    for (i=1;i<=dp[n-1][m-1];i++)
        printf("%d ",p[i]);

    return 0;

}
