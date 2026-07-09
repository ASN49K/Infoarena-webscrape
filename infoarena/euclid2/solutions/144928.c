# include <stdio.h>


int cmmdc (int a,int b){
	int p;
	if(b==0)
		return a;
	else if(a==0)
		return b;
	if( a>b )
		p=cmmdc(a%b,b);
	else p=cmmdc(a,b%a);
	return p;
}


int main(){
	int a,b,result;
	FILE *in=fopen("euclid2.in","r");
	fscanf(in,"%d %d",&a,&b);
	fclose(in);
	result=cmmdc(a,b);
	FILE *out=fopen("euclid2.out","w");
		fprintf(out,"%d",result);
	fclose(out);
	return 0;
}
