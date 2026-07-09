#include<stdio.h>
FILE*f=fopen("sirmax.in","r");
FILE*g=fopen("sirmax.out","w");
int j,n,i,p,u,m,x,v[101],w[101],s[101],k,a[102][101];

int main() {
	fscanf(f,"%d",&n);
	for(i=1;i<=n;++i)
		fscanf(f,"%d",&v[i]);
	
	v[n+1]=32001;
	
	for(i=1;i<=n+1;++i){
		for(j=0;j<i;++j)
			if(v[i]>v[j]){
				w[i]=w[j]+1;
				if(w[i]==w[j]+1)
					a[i][++k]=j;
			}
		k=0;	
	}
	
	
	x=w[0];
	

	
	
	fclose(g);
	fclose(f);
	return 0;
}