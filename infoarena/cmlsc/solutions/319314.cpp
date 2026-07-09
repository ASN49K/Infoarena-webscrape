#include <stdio.h>
#include <math.h>
FILE *f;   
int main(void){
	int n,m;
	f=fopen("cmlsc.in","r");   
    fscanf(f,"%d %d",&m,&n);   
    int a[m],b[n];
    int i;
	for (i=1;i<=m;i++){
		fscanf(f,"%d",&a[i]);
	}
    for (i=1;i<=n;i++){
		fscanf(f,"%d",&b[i]);
	} 
	int j,c=0;
	int v[1024];
	fclose(f);
	for (i=1;i<=m;i++){
		for (j=1;j<=n;j++){
			if (a[i]==b[j]){
				c=c+1;
				v[c]=a[i];
			}
		}
	}
	f=fopen("cmlsc.out","w");
	fprintf(f,"%d\n",c);
	for (i=1;i<=c;i++){
		fprintf(f,"%d ",v[i]);
	}
}
