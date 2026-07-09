# include <stdio.h>

# define input "cmlsc.in"
# define output "cmlsc.out"

# define MAX 1025
# define max(a,b) (a>b?a:b)

int a[MAX][MAX];
int n,i,v1[MAX],v2[MAX],j,m;
int res[MAX];

int main()
{
    freopen(input, "r", stdin);
    freopen(output, "w",stdout);
    
    scanf("%d%d",&n,&m);
    
    for(i=1;i<=n;i++)
       scanf("%d",&v1[i]);
    for(i=1;i<=m;i++)
       scanf("%d",&v2[i]);       
       
    for(i=1;i<=n;i++)
      for(j=1;j<=n;j++)
         if(v1[i] == v2[j])
           a[i][j] = a[i-1][j-1]+1;
         else
           a[i][j] = max(a[i-1][j],a[i][j-1]);
    
    printf("%d\n",a[n][m]);
    i=n;j=m;
    int pos = 0;
    while(i>=1 && j>=1)
    {
        if(v1[i] == v2[j])
            res[++pos] = v1[i],i--,j--;
        else
          if(a[i-1][j] > a[i][j-1])
             i--;
          else
             j--;
    }
    for(i=pos;i;i--)
       printf("%d ",res[i]+1);
    return 0;
}
