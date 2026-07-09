#include<stdio.h>
#include<stdlib.h>

void cLS(int m, int n, int a[], int b[]){
	FILE * out = fopen("cmlsc.out","w");
	int aux,contor=0,i,j,c[ m>n ? n : m];
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if( a[i]==b[j] ) c[contor++]=a[i];
		}
	}
	fprintf(out,"%d\n",contor);
	for(i=0; i<contor; i++)
	    fprintf(out,"%d ",c[i]);
	fclose(out);
}

void extrag(FILE *f, int n, int a[]){
	int i;
	for(i=0; i<n; i++){
		fscanf(f,"%d",&a[i]);
		}
	}

int main(){
	FILE *f = fopen("cmlsc.in","r");
	int m,n,i;
	fscanf(f,"%d%d",&m,&n);
	int a[m],b[n];
	extrag(f,m,a);
	extrag(f,n,b);
	cLS(m,n,a,b);
	fclose(f);
	getchar();
	return 0;
	system("pause");
}
