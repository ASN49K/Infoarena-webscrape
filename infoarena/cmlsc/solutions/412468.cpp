#include <stdio.h>

int i,n,m,x,max,x2,k,v[100],w[100],s[100],sol,x3,x4;

int main(){
	FILE *f = fopen ("cmlsc.in","r");
	FILE *g = fopen ("cmlsc.out","w");
	fscanf(f,"%d %d",&n,&m);
	for(i=1;i<=n;i++){
		fscanf(f,"%d",&x);
		v[x] = i;
		if(x>max)
			max = x;
	}
	for(i=1;i<=m;i++){
		fscanf(f,"%d",&x);
		w[x] = i;
		if(x>max)
			max = x;
	}
	
	x=0;
	x2=0;
	for(i=1; i<=max; i++){
		if(v[i] != 0 && w[i] !=0){
			if(v[i] > x && w[i] > x2){
				s[++k] = i;
				if(k>sol)
					sol = k;
				x3=x;
				x4=x2;
				x=v[i];
				x2=w[i];

			}else{
				x=x3;
				x2 = x4;
				k--;
				i--;
			}
		}
	}
	fprintf(g,"%d\n",sol);
	for(i=1;i<=sol;i++)
		fprintf(g,"%d ",s[i]);
	
	fclose(f);fclose(g);
	return 0;
}