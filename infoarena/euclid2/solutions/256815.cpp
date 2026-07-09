#include <stdio.h>

FILE *in,*out;

int cm(int a,int b)
{
	if(!b)
		return a;
	return cm(b,a%b);
}

int main()
{
long n,i,a,b;

in = fopen ("euclid2.in","r");
out = fopen ("euclid2.out","w");
fscanf(in,"%ld",&n);

for(i=1;i<=n;i++)
{
	fscanf(in,"%ld %ld",&a,&b);
	fprintf(out,"%ld \n",cm(a,b));
}

fclose(in);
fclose(out);
return 0;

}