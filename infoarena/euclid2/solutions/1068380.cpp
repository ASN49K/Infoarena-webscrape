#include<stdio.h>
int main ()
{
	FILE *fin,*fout;
	fin=fopen ("euclid2.in","r");
	fout=fopen ("euclid2.out","w");
	int n,a,b,d,i;
	fscanf (fin,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf (fin,"%d%d",&a,&b);
		while (b!=0)
		{
			d=b;
			b=a%b;
			a=d;
		}
		fprintf (fout,"%d\n",d);
	}
	return 0;
}
