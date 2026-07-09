#include<stdio.h>
FILE*f=fopen("sirmax.in","r");
FILE*g=fopen("sirmax.out","w");
int n,i,p,u,m,x,v[101],w[101],s[101];

void back(int k) {
	if(k==x){
		for(i=1;i<=x;++i)
			fprintf(g,"%d ",s[i]);
		fprintf(g,"\n");
	}else
		for(int i=1;i<=n;++i)
			if(v[i]>v[s[k]]&&s[k]<i){
				s[k+1]=i;
				back(k+1);
			}

}
int main() {
	fscanf(f,"%d",&n);
	for(i=1;i<=n;++i)
		fscanf(f,"%d",&v[i]);
	
	w[1]=w[0]=1;
	for(int i=2;i<=n;++i){
		p=1;
		u=w[0];
		while(p<=u){
			m=(p+u)/2;
			if(v[i]>v[w[m]])
				p=m+1;
			else
				u=m-1;
		}
		
		w[p]=i;
		if(p>w[0])
			w[0]=p;	
		
	}

	x=w[0];
	
	back(0);
	
	fclose(g);
	fclose(f);
	return 0;
}
