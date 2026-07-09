#include <cstdio>
using namespace std;

FILE *f=fopen ("cmmdc.in","r");
FILE *g=fopen ("cmmdc.out","w");

int main(){
	int a,b,r;
	
	fscanf (f,"%d%d",&a,&b);
	
	r=a%b;
	while (r!=0){
		a=b;
		b=r;
		r=a%b;
	}
	if (b==1){
		b=0;
	}
	fprintf (g,"%d",b);
	
	return 0;
}
