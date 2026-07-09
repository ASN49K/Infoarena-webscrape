#include<stdio.h>
int t,a,b,c;
FILE *in,*out;
int main()
{
	in=fopen("euclid2.in","r");
	out=fopen("euclid2.out","w");
	fscanf(in,"%d",&t);
	for(;t>0;t--)
	{
		fscanf(in,"%d %d",&a,&b);
		while(b)
		{
			c=a%b;
			a=b;
			b=c;
		}
	    fprintf(out,"%d\n",a);
		//fputc('\n',out);
	}
	fclose(in);fclose(out);
}