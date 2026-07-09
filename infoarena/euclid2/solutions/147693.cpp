#include <stdio.h>
int main()
{
	FILE *in,*out;
	int a,b,r;
	in=fopen("euclid2.in","r");
	out=fopen("euclid2.out","w");
	fscanf(in,"%d%d",&a,&b);
	 r=a%b;  
     while (r)  
     {  
         a=b;  
         b=r;  
         r=a%b;  
     }
	fprintf(out,"%d\n",b);
	fclose(in);
	fclose (out);
	return 0;
}
