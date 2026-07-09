#include<stdio.h>
FILE *fin,*fout;
int main()
{
	fin = fopen("euclid2.in","r");
	fout = fopen("euclid2.out","w");

	long a,b,r,T;
	
	fscanf(fin,"%ld",&T);

	for(int i=0;i<T;i++){

		fscanf(fin,"%ld %ld",&a,&b);

		do

		{	r=a%b;

			a=b;

			b=r;

		}while(r);


		fprintf(fout,"%ld\n",a);
	}

	return 0;
}