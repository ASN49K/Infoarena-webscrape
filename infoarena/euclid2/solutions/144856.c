# include <stdio.h>


int cmmdc (int a,int b){
	if(a==0) 
		return b;
	if(b==0) 
		return a;
	if(a>b) 
		return cmmdc(a-b,b);
	return cmmdc(b-a,a);
}


int main(){
	int a,b,result;
	FILE *in=fopen("euclid2.in","r");
	fscanf(in,"%d %d",&a,&b);
	fclose(in);
	result=cmmdc(a,b);
	FILE *out=fopen("euclid2.out","w");
	if(result!=1)
		fprintf(out,"%d",result);
	else
		fprintf(out,"%d",0);
	fclose(out);
	return 0;
}
