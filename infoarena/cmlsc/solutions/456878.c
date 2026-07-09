/*
 * test
 *
 *  Created on: May 16, 2010
int main() *      Author: Adrian
 */
#include<stdio.h>
#include<io.h>
#include<stdlib.h>

int min(int a, int b) {
	if (a>b)return a;
	return b;
}
int main() {
	char flag;
	FILE *in=fopen("cmlsc.in","r"), *out=fopen("cmlsc.out","w");
	int i,j,n,m,*a=0,*b=0,nr=0,*c=0;
	fscanf(in,"%d %d",&n,&m);
	a=(int *)malloc(n*sizeof(int));
	b=(int *)malloc(m*sizeof(int));
	c=(int*)malloc(min(n,m)*sizeof(int));

	for(i=0;i<n;i++)
		fscanf(in,"%d",&a[i]);
	for(i=0;i<n;i++) {
		flag=0;
		for(j=0;j<m;j++) {
			fscanf(in,"%d",&b[j]);
			if(a[i]==b[j]) { flag=1; nr++; }
		}
		if (flag==1) c[nr-1]=a[i];
	}

	rewind(out);
	fprintf(out,"%d\n",nr);
	for(i=0;i<nr;i++)
		fprintf(out,"%d ",c[i]);

	return 0;
}
