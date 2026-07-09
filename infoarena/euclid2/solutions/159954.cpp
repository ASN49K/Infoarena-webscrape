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

		if (a==0)
			c=a;
		 else
		 {
			while (b>0)
			{
				if (a>b)
					a=a-b;
				else
					b=b-a;
            }
			c=a;
		 }

		 fprintf (s,"%ld\n",c);

	}


	fcloseall();

	return 0;

}
