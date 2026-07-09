#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a, int b){
	if(a>=b) return a;
	return b;
}

int main(){
	FILE *f = fopen("cmlsc.in","r");
	FILE *g = fopen("cmlsc.out","w");
	
	int n,m,i,j,bst=0;
	int *sir,*a,*b,**d;
	
	fscanf(f,"%d %d\n",&n,&m);
	
	a = (int*)malloc((n+1)*sizeof(int));
	b = (int*)malloc((m+1)*sizeof(int));
	d = (int**)malloc((n+1)*sizeof(int*));
	for(i=0;i<=n;i++)
		d[i] = (int*)calloc((m+1),sizeof(int));
	sir = (int*)malloc((m+n)*sizeof(int));
	
	for(i=1;i<=n;i++)
		fscanf(f,"%d ",&a[i]);
	for(i=1;i<=m;i++)
		fscanf(f,"%d ",&b[i]);
		
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i] == b[j])
				d[i][j] = d[i-1][j-1] + 1;
			else
				d[i][j] = max(d[i-1][j],d[i][j-1]);
			
	for(i=n, j=m; i; )
		if(a[i] == b[j])
		{
			sir[++bst] = a[i];
			i--;
			j--;
		}
		else{
			if(d[i-1][j]<d[i][j-1])
				j--;
			else
				i--;
		}		
	fprintf(g,"%d\n",bst);
	for(i=bst;i;i--)
		fprintf(g,"%d ",sir[i]);
	fprintf(g,"\n");
	
	return 0;
	
	
}
