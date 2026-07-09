#include <stdio.h>
#include <math.h>

FILE* f;
FILE* s;

int main()
{
	f=fopen ("euclid2.in","r");
	s=fopen ("euclid2.out","w");

	long int t;
	fscanf (f,"%ld\n",&t);

	long int a;
	long int b;
	long int c;
	for (long int i=1;i<=t;i++)
	{
		fscanf (f,"%ld %ld\n",&a,&b);

		c=a%b;
		while(c!=0)
		{

			a=b;
			b=c;
			c=a%b;
   		}  

		 fprintf (s,"%ld\n",b);

	}


	fcloseall();

	return 0;

}
