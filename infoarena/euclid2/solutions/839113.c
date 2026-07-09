#include <stdio.h>

int Cmmdc(int,int);

int main(int argc, char *argv[])
{
	int m,x,y;
	FILE * fin , * fout;

	if(argc > 1)
	{
		fin = fopen("test.in","r");
		fout = fopen("test.out","w");

		fscanf(fin,"%d",&m);
		while(m--)
		{
			fscanf(fin,"%d %d",&x,&y);
			fprintf(fout,"%d\n",Cmmdc(x,y));
		}
	} else 
	{
		fin = fopen("euclid2.in","r");
		fout = fopen("euclid2.out","w");

		fscanf(fin,"%d",&m);
		while(m--)
		{
			fscanf(fin,"%d %d",&x,&y);
			fprintf(fout,"%d\n",Cmmdc(x,y));
		}
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

// Cel mai mare divizor comun
int Cmmdc(int a,int b)
{
	if(b == 0) return a; else return Cmmdc(b,a%b);
}