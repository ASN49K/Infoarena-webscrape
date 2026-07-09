#include<stdio.h>
#include<stdlib.h>

void extrag(FILE *f, int n, int a[]){
	int i;
	for(i=0; i<n; i++){
		fscanf(f,"%d",&a[i]);
		}
}

int cmlsc(int m, int n, int a[], int b[], int v[]){
	int c[m+1][n+1],i,k=0,j;
	for(i=0; i<m+1; i++)
	    c[i][0]=0;
	for(j=0; j<n+1; j++)
	    c[0][j]=0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			if( a[i]==b[j] ){
			    c[i+1][j+1]=c[i][j]+1;
				v[k]=i;
				k++;
			}
			else
			    c[i+1][j+1]=c[i][j+1]>c[i+1][j] ? c[i][j+1] : c[i+1][j];
		}
	}
	return c[m][n];
}



int main(){
	FILE *f = fopen("cmlsc.in","r");
	FILE * out = fopen("cmlsc.out","w");
	int m,n,i;
	fscanf(f,"%d%d",&m,&n);
	int a[m],b[n],v[m>n ? n : m];
	extrag(f,m,a);
	extrag(f,n,b);
	fclose(f);
	int r = cmlsc(m,n,a,b,v);
	fprintf(out,"%d\n",r);
	for(i=0; i<r; i++)
	    fprintf(out,"%d ", a[v[i]]);
	fclose(out);
	getchar();
	return 0;
	system("pause");
}
