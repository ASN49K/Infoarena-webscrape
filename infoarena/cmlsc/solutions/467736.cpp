#include<stdio.h>
#define maxim(a,b) ((a>b)?a:b)
int A[1025],B[1025],D[1025][1025],sir[1025],bst;

int main()
{
	
	int m,n,i,j;
    freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	scanf("%d %d\n",&m,&n);
	for(i=1;i<=m;i++) scanf("%d ",&A[i]);
	for(i=1;i<=n;i++) scanf("%d ",&B[i]);
    for(i=1;i<=m;i++)
	   for(j=1;j<=n;j++)
	   {	
	   if(A[i]==B[j]) D[i][j]=D[i-1][j-1]+1;
	   else D[i][j]= maxim(D[i-1][j],D[i][j-1]);
	   }
	   
  
	for(i=n,j=m; i;)
		if(A[i]==B[j])
			bst++,sir[bst]=A[i],--i,--j;
		else if(D[i-1][j]<D[i][j-1])
			--j;
		else 
			--i;
bst=D[m][n];		
printf("%d\n",bst);
for(i=bst;i>0;--i)
	printf("%d ",sir[i]);


			
return 0;
}