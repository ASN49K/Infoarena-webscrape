#include<stdio.h>
int t,a,b;
FILE *in,*out;
int main()
{
	in=fopen("euclid2.in","r");
	out=fopen("euclid2.out","w");
	fscanf(in,"%d",&t);
	for(;t>0;t--)
	{
		fscanf(in,"%d %d",&a,&b);
		while(a!=b)
			if(!a%b)a=b;
		else if(!b%a)b=a;
			else if(a>b)a-=b;
		else b-=a;
	    fprintf(out,"%d\n",a);
	}
	fclose(in);fclose(out);
}