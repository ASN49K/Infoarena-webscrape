#include <cstdio>

int n,m,i,j,bst;

int a[1024],b[1024];

int c[1024][1024];

int sir[1024];

int main()
{
	
		freopen("cmlsc.in", "r", stdin);
		freopen("cmlsc.out", "w", stdout);
		
		scanf("%d%d", &n, &m);

		for (i=1;i<=n;i++)
			scanf("%d", &a[i]);
		for (j=1;j<=n;j++)
			scanf("%d", &b[i]);
		
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				if (a[i]==b[j])
				{
					c[i][j]=c[i-1][j-1]+1;
					continue ;
				}
				
				if ( c[i-1][j]> c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					continue;
				}
				
				c[i][j]=c[i][j-1];
					
			}
	for (i =1, j = n; i; )
    
		if (a[i] == b[j])
           sir[++bst] = a[i], --i, --j;
        else if (c[i-1][j] < c[i][j-1])
            --j;
        else
            --i;
 
    printf("%d\n", bst);
    for (i = bst; i; --i)
     printf("%d ", sir[i]);
	
	
	return 0;
}
