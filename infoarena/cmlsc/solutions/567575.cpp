#include <stdio.h>
#define max(a,b) (a>b?a:b)
FILE *f=fopen("cmlsc.in","r");
FILE *g=fopen("cmlsc.out","w");
int n,m,A[1025],B[1025];
long d[1025][1025];
int sol[1025];

int main(void){
	register int i,j;
	
	fscanf(f,"%d %d",&n,&m);
	for(i=1;i<=n;i++){
		fscanf(f,"%d",&A[i]);
	}
	for(i=1;i<=n;i++){
		fscanf(f,"%d",&B[i]);
	}
	fclose(f);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(A[i]==B[j]){
				d[i][j]=1+d[i-1][j-1];
			}
			else{
				d[i][j]=max(d[i-1][j],d[i][j-1]);
			}
		}
	}
	
	int q=0;
	i=n,j=m;
	for (i=n,j=m;i;){
		if(A[i]==B[j]){
			sol[++q]=A[i];
			i--,j--;
		}
		else if(d[i-1][j]<d[i][j-1])
			j--;
		else
			i--;
	}
	
	fprintf(g,"%d\n",q);
	for(;q>=1;q--){
		fprintf(g,"%d ",sol[q]);
	}
	fclose(g);
	return 0;
}