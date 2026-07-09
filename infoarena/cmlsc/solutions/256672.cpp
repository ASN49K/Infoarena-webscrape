#include<stdio.h>
#define NMAX 1125
#define maxim(a,b) a>b? a:b
int a[NMAX][NMAX],b[NMAX],c[NMAX],n,m,sol[NMAX],lung=0;

int main()
{int i,j,pozi=0,pozj=0,max=0;;
freopen("cmlsc.in","r",stdin);
freopen("cmlsc.out","w",stdout);
scanf("%d%d",&n,&m);
	  for(i=1;i<=n;i++)
		  scanf("%d",&b[i]);
	  for(i=1;i<=m;i++)
		  scanf("%d",&c[i]);
		
	for(i=1;i<=n;i++)	
		for(j=1;j<=m;j++)
			if(b[i]==c[j])		
				a[i][j]=1+a[i-1][j-1];		
			else a[i][j]=maxim(a[i-1][j],a[i][j-1]);
	
 for (i = n, j = m; j; )  
        if (b[i] == c[j])  
             sol[++lung] = b[i], --i, --j;  
        else if (a[i-1][j] < a[i][j-1])  
             --j;  
        else  
             --i; 
	printf("%d\n",lung);
	for(i=lung;i;i--)
		printf("%d ",sol[i]);
return 0;}
