#include <stdio.h>

FILE* f;
FILE* s;

int m;
int n;

int a[1100];
int b[1100];
int c[1100];


int main()
{

	f=fopen ("cmlsc.in","r");
	s=fopen ("cmlsc.out","w");

	fscanf (f,"%d %d\n",&m,&n);

	//-----------------------------------------------------------------------

	int al;
	int bl;

	if (m>n)
	{
		al=m;
		bl=n;

		for (int i=1;i<=m;i++)
			fscanf (f,"%d ",&a[i]);

		fscanf (f,"\n");

		for (int j=1;j<=n;j++)
			fscanf (f,"%d ",&b[j]);
	}
	else
	{
		al=n;
		bl=m;

		for (int i=1;i<=m;i++)
			fscanf (f,"%d ",&b[i]);

		fscanf (f,"\n");

		for (int j=1;j<=n;j++)
			fscanf (f,"%d ",&a[j]);

	}

	//-----------------------------------------------------------------------


	int lung=0;

	int inc=1;

	for (int i=1;i<=al;i++)
	{
		for (int j=inc;j<=bl;j++)
		{
			if (a[i]==b[j])
			{
				c[j]=a[i];

				inc=j+1;

				lung++;

				break;

			}
		}
	}

	//-----------------------------------------------------------------------

	fprintf (s,"%d\n",lung);

	for (i=1;i<=al;i++)
	{
		if (c[i]>0)
			fprintf (s,"%d ",c[i]);
	}

	fcloseall();

	return 0;
}