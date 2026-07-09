#include <cstdio>
using namespace std;
int t,i,a,b,r;
int main()
{FILE*f=fopen("euclid2.in","r");
FILE*g=fopen("euclid2.out","w");
fscanf(f,"%d",&t);
for(i=1; i<=t; i++){
	fscanf(f,"%d %d",&a,&b);
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	fprintf(g,"%d",a);
	fprintf(g,"\n");
}
}