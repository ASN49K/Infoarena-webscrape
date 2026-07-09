#include<stdio.h>
FILE*f=fopen("sirmax.in","r");
FILE*g=fopen("sirmax.out","w");
int j,n,i,p,u,m,x,v[101],w[101],s[101],k,a[102][101];

void sol() {
	
	for(i=w[n+1];i>1;--i)
		fprintf(g,"%d ",s[i]);
	fprintf(g,"\n");
	
	
}
void rec(int p,int niv){
	if(p==0)
		sol();
	else{
		if(v[s[niv-1]]>v[p]|niv==1){
			s[niv]=p;
			for(int i=1;i<=a[p][0];++i)
				rec(a[p][i],niv+1);
		}
	}
	
}
int main() {
	fscanf(f,"%d",&n);
	for(i=1;i<=n;++i)
		fscanf(f,"%d",&v[i]);
	
	v[n+1]=32001;
	
	for(i=1;i<=n+1;++i){
		int max=0;
		for(j=0;j<i;++j)
			if(max<w[j]+1&&v[i]>v[j])
				max=w[j]+1;
		w[i]=max;	
		for(j=0;j<i;++j)
			if(w[i]==w[j]+1)
				a[i][++k]=j;
						
		a[i][0]=k;
		k=0;	
	}
	
	
	rec(n+1,1);

	
	
	fclose(g);
	fclose(f);
	return 0;
}
