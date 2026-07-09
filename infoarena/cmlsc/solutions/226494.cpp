#include<stdio.h>
int a[1025];
int b[1025];
int n,m;
int common[1024];
int din[1025][1025];
int max(int k1, int k2) {if (k1>k2) return k1; return k2;}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i = 1; i<=n; i++)
     scanf("%d",&a[i]);
    for(int i = 1; i<=m; i++)
     scanf("%d",&b[i]);
    for(int i = 1; i<=n; i++)
     for(int j = 1; j<=m; j++)
     {
      if (a[i]==b[j])
            din[i][j] = din[i-1][j-1] + 1;
        else
        din[i][j] = max(din[i-1][j],din[i][j-1]);
     }
    for(int i=n,j=m;i!=0 && j!=0;)
     {
         if (a[i] == b[j])
           {
            common[++common[0]] = a[i];
            i--;
            j--;
           }
          else
         if (din[i-1][j] > din[i][j-1])
            i--;
          else
            j--;

     }
    printf("%d \n", din[n][m]);
    for(int i = common[0]; i > 0; i--)
     printf("%d ",common[i]);
    return 0;
}

