#include<stdio.h>
using namespace std;
int main(){
	FILE *f,*g;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	int a,b,x,r,i;
	fscanf(f,"%d",&x);
	for(i=1;i<=x;i++)
	{
		fscanf(f,"%d%d",&a,&b);
		if(a<b)
		{
			r=a;
			a=b;
			b=r;
		}
		r=a%b;
		while(r>0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		fprintf(g,"%d",b);
		fprintf(g,"\n");
	}
	fclose(f);
	fclose(g);
	return 0;
}
	