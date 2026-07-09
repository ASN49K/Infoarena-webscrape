#include "stdio.h"

int cmmdc(int a, int b){
	int c = a+b;
	while(a!=b){
		if(a>b){
			a = a-b;
		}
		else{
			b = b-a;
		}
	}
	if((c>3)&&(a==1))
		return 0;
	return a;

}

int main(){
	int a,b;

	FILE *f,*g;
	f = fopen("cmmdc.in","r");
	g = fopen("cmmdc.out","w");

	fscanf(f,"%d %d",&a,&b);
	fprintf(g,"%d",cmmdc(a,b));
	return 0;
}