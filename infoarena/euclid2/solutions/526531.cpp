#include<stdio.h>
FILE *fin,*fout;
int m,n,v[10001],i,j,d,k;

int cmmdc(int a, int b){
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}

int main(){
fin=fopen("oz.in","r");
fout=fopen("oz.out","w");
fscanf(fin,"%d %d",&n,&m);
for(i=1;i<=n;i++){
	v[i]=1;
}
for(k=1;k<=m;k++){
	fscanf(fin,"%d %d %d\n",&i,&j,&d);
	v[i]=v[i]*d/cmmdc(v[i],d);
	v[j]=v[j]*d/cmmdc(v[j],d);
	if(cmmdc(v[i],v[j])!=d || v[i]>=2000000000 || v[j]>=2000000000){
		fprintf(fout,"-1 ");
		return 0;
	}
	
}

for(i=1;i<=n;i++){
	fprintf(fout,"%d ",v[i]);
}
return 0;
}