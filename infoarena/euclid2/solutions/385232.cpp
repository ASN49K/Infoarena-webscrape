#include<stdio.h>
FILE *fin, *fout;
int a,b,i,t,x;


int cmmdc(int a, int b){
int r;

	r=a%b;
	while(r>0){
		a=b;
		b=r;
		r=a%b;
	}


return b;
}


int main(){

	fin=fopen("euclid2.in","r");
	fout=fopen("euclid2.out","w");

	fscanf(fin,"%d",&t);

	for(i=1;i<=t;i++){
		fscanf(fin,"%d %d",&a,&b);
		x=cmmdc(a,b);
		fprintf(fout,"%ld\n",x);
	}

	fclose(fout);
	fclose(fin);

return 0;
}