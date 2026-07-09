#include<stdio.h>

int a[100],b[100],n,i,m,j,c[100],k;

int main(){
FILE *f = fopen("cmlsc.in","r");
FILE *g = fopen("cmlsc.out","w");

fscanf(f,"%d%d",&n,&m);
for(i=1;i<=n;i++)
	fscanf(f,"%d",&a[i]);

for(i=1;i<=m;i++)
	fscanf(f,"%d",&b[i]);

for(i=1;i<=n;i++)
	for(j=1;j<=m;j++){
		if(a[i] == b[j]){
			c[++k] = a[i];
		}
	}

fprintf(g,"%d\n",k);

for(i=1;i<=k;i++)
	fprintf(g,"%d ",c[i]);

fclose(f);
fclose(g);

return 0;
}