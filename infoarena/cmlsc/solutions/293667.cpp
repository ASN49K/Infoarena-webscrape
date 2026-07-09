#include<stdio.h>

int n,m,i,j,k;
int a[1000][1000],b[1000005];

int main()
{
    int ma;
    freopen("spirala.in","r",stdin);
    freopen("spirala.out","w",stdout);
    scanf("%d%d",&n,&m);
    
    for(i = 0; i < m; i++)
      for(j = 0; j < n; j++)           
         scanf("%d",&a[i][j]);
    for(int t = 0; t < (m / 2) + 1; t++)
    {
       for(i = t; i < n - t; i++)
         b[k++] = a[t][i];
       for(j = t+1; j < m - t - 1; j++)
         b[k++] = a[j][n-t-1];
       for(i = n - t - 1; i >= t; i--)
         b[k++] = a[m - t - 1][i];                 
       for(j = m - t - 2; j > t; j--)
         b[k++] = a[j][t];             
    }
    
    ma = b[1] - b[0];
    for(i = 0; i < k-2;i++)  
     if(b[i+1]-b[i] != ma) 
     { 
        printf("NU\n%d %d\n",b[i],b[i+1]);
        return 0; 
     }
    printf("DA\n%d\n",b[k-1]);
    return 0;
}
