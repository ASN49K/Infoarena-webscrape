#include<stdio.h>
#include<stdlib.h>

int euclid(int a,int b)
{
	int r;
	while(b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main(void)
{
	FILE * fin = fopen("euclid2.in","rt");
	if( !fin)
		return -1;
	FILE * fout = fopen("euclid2.out","wt");
	if( !fout)
	{
		fclose(fin);
		return -1;
	}
	int t;
	fscanf(fin,"%d",&t);
	while(t > 0)
	{
		int a,b;
		fscanf(fin,"%d%d",&a,&b);
		int res = euclid(a,b);
		fprintf(fout,"%d\n",res);
		t--;
	}
	fclose(fin);
	fclose(fout);
	return 0;
}


