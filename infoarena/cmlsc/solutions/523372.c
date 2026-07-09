#include<stdio.h>
	int A[1024],B[1024],C[257],m,n,k;
	void CITIRE()
	{
		int i;
		FILE* intrare = fopen("cmlsc.in","r");
		fscanf(intrare,"%d %d\n",&m,&n);
		for(i=0;i<m;i++)
			fscanf(intrare,"%d ",&A[i]);
		for(i=0;i<n;i++)
			fscanf(intrare,"%d ",&B[i]);
		fclose(intrare);
	}
	void DETECTARE()
	{
		int a,b,gasit1=0,gasit2=0;
		for(a=0;a<=256;a++)
			{
			gasit1=0;
			gasit2=0;
			for(b=0;b<m;b++)
				if(A[b]==a)
					gasit1++;
			for(b=0;b<n;b++)
				if(B[b]==a)
					gasit2++;
			if(gasit1>=gasit2)
				{
				C[a]=gasit2;
				k+=gasit2;
				}
			if(gasit2>gasit1)
				{
				C[a]=gasit1;
				k+=gasit1;
				}
			}
	}
	void AFISARE()
	{
		int i;
		FILE* iesire = fopen("cmlsc.out","w");
		fprintf(iesire,"%d\n",k);
		for(i=0;i<=256;i++)
			while(C[i]>0)
				{
					fprintf(iesire,"%d ",i);
					C[i]--;
				}
		fclose(iesire);
	}
	void main()
	{
		CITIRE();
		DETECTARE();
		AFISARE();
	}
			
