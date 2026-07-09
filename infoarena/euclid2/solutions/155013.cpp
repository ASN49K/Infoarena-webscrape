#include<stdio.h>
long a,b,c,t;
int main()
{	FILE *f=fopen("euclid2.in","r"),
	     *g=fopen("euclid2.out","w");
	fscanf(f,"%ld",&t);
	for(;t;t--)
	{ fscanf(f,"%ld%ld",&a,&b);
	  while(b) {c=b; b=a%b; a=c;}
	  fprintf(g,"%ld\n",a);
	}
	fcloseall();
	return 0;
}

