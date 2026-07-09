#include <stdio.h>
#include <stdlib.h>

int max (int a, int b){
	int m=a;
	if (b > a) m=b;
	return m;	
}

int** alocmat(int n){
	int ** m;
	m=(int**) malloc(n * sizeof(int*));
	int i;
	for (i = 0;i < n;++i)
		m[i]=(int*)calloc(n, sizeof(int));
	return m;
}

void free_mat (int **m,int l){
	int i;
	for (i=0;i<l;++i)
		free(m[i]);
	free(m);
}

int main(){
	int *a,*b,n,m,i,j,nr=0,*sir,**c;
	FILE *in,*out;
	
	in=fopen("cmlsc.in","r");
	out=fopen("cmlsc.out","w");
	
	fscanf(in,"%d %d",&n,&m);
	a=(int*)malloc((n+1)*sizeof(int));
	b=(int*)malloc((m+1)*sizeof(int));
	sir=(int*)malloc((max(n,m)+1)*sizeof(int));
	c=alocmat(max(m,n)+1);
	
	for (i=1;i<=n;++i)
		fscanf(in,"%d",&a[i]);
	for (i=1;i<=m;++i)
		fscanf(in,"%d",&b[i]);
	
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (a[i]==b[j])
				c[i][j]=1+c[i-1][j-1];
			else
				c[i][j]=max(c[i][j-1],c[i-1][j]);

	for (i=n,j=m;i&&j;)
		if (a[i]==b[j]){
			sir[++nr] = a[i];
			--i; 
			--j;
		}
		else 
			if (c[i-1][j]<c[i][j-1])
				--j;
			else	--i;
			
	fprintf(out,"%d\n",nr);
	for (i=nr;i;--i)
		fprintf(out,"%d ",sir[i]);
	free(a);
	free(b);
	free(sir);
	free_mat(c,max(n,m));
	return 0;
}
