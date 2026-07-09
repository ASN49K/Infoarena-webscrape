#include<stdio.h>
#define max(a,b) ((a>b)?a :b)

int A[1025],B[1025],C[1025][1025],m,n,bst,sir[1025];


int main()
{
	int i,j;
	
	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d %d\n",&m,&n);
     for(i=1;i<=m;i++)
		 scanf("%d ",&A[i]);
	 for(j=1;j<=n;j++)
		 scanf("%d ",&B[j]);
	 
	 for(i=1;i<=m;i++)
		 for(j=1;j<=n;j++)
			 
		if(A[i]==B[j])
			C[i][j]=C[i-1][j-1]+1;
		else
			C[i][j]=max(C[i-1][j],C[i][j-1]);
		
	
		for(i=m,j=n;i;)
			if(A[i]==B[i])
				bst++,sir[bst]=A[i],i--,j--;
			else if(C[i-1][j]<C[i][j-1])
				j--;
			else
				i--;

printf("%d\n",bst);			
 for(i=bst;i>0;i--)
	 printf("%d ",sir[i]);
 
return 0;

}