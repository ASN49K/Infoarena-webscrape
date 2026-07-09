#include <stdio.h>

long euclid(long a,long b)
{
if(b==0) return a;
return euclid(b, a%b);
}

int main()
{
long a,b,t;
FILE *f,*g;

f=fopen("euclid2.in","r");
g=fopen("euclid2.out","w");

fscanf(f,"%ld",&t);

while(t)
	{
	t--;
	fscanf(f,"%ld %ld",&a,&b);
	fprintf(g,"%ld\n",euclid(a,b));
	}

fclose(f);
fclose(g);

return 0;
}
