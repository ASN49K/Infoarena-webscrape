#include<stdio.h>
long ok,a,b,m,n,i,j,k,max;
int v1[1025],v2[1025],v[1025],vv[1025];
FILE *f1,*f2;
int main(){
f1=fopen("cmlsc.in","r");
f2=fopen("cmlsc.out","w");
fscanf(f1,"%ld%ld",&m,&n);
for(i=1;i<=m;fscanf(f1,"%d",&v1[i]),i++);
for(i=1;i<=n;fscanf(f1,"%d",&v2[i]),i++);
for(i=1;i<=m;i++){
	ok=1;
	for(j=1;j<=n&&ok;j++){
		if(v1[i]==v2[j]){
			k++;
			ok=0;
			v[k]=j;
		}
	}
}
max=0;
for(i=1;i<=k;i++){
	vv[i]=1;
	for(j=1;j<i;j++){
		if(v[j]<v[i]&&vv[i]<vv[j]+1){
			vv[i]=vv[j]+1;
			if(vv[i]>max){
				max=vv[i];
			}
		}
	}
}
fprintf(f2,"%ld\n",max);
i=0;
j=1;
while(i<max){
	i++;
	while(vv[j]!=i){
		j++;
	}
	fprintf(f2,"%d",v2[v[j]]);
	if(i<max){
		fprintf(f2," ");
	}
}
return 0;}
