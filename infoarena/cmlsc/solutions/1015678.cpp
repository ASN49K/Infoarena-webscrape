//subsir comun maximal al doua siruri

#include <stdio.h>

int a[1026],b[1026],lg[1026][1026],n,m;

void afisare(int i,int j,int pas)
{
    if(pas)
    {
        if(a[i]==b[j])
        {
            afisare(i-1,j-1,pas-1);
            printf("%d ",a[i]);
        }
        else
          if(lg[i][j-1]==pas)
             afisare(i,j-1,pas);
           else
             afisare(i-1,j,pas);
    }
}

int main()
{
    int i,j;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
       {
           scanf("%d",&a[i]);
       }
    for(i=1;i<=m;i++)
       {
           scanf("%d",&b[i]);
       }
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
         if(a[i]==b[j])
            lg[i][j]=1+lg[i-1][j-1];
         else
            if(lg[i-1][j]>lg[i][j-1])
                lg[i][j]=lg[i-1][j];
            else
                lg[i][j]=lg[i][j-1];

    printf("%d\n",lg[n][m]);
    afisare(n,m,lg[n][m]);
    return 0;
}

