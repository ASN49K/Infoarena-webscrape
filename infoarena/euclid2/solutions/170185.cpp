#include<stdio.h>
#include<string.h>
long a,b,n1,n2,i,j;
FILE *f1,*f2;
long cmmdc(long n1,long n2){
if(n2!=0){
	return cmmdc(n2,n1%n2);
}
return n1;
}
int main(){
f1=fopen("euclid2.in","r");
f2=fopen("euclid2.out","w");
fscanf(f1,"%ld",&a);
for(i=1;i<=a;i++){
	fscanf(f1,"%ld%ld",&n1,&n2);
	fprintf(f2,"%ld",cmmdc(n1,n2));
	if(i<a){
		fprintf(f2,"\n");
	}
}
return 0;}
