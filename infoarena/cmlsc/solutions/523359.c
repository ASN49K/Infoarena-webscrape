#include<stdio.h>
	int A[1024],B[1024],C[1024],m,n,k;
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
		int i,j;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(A[i]==B[j])
					{					
					C[k]=A[i];
					k++;
					}
	}
	void AFISARE()
	{
		int i;
		FILE* iesire = fopen("cmlsc.out","w");
		fprintf(iesire,"%d\n",k);
		for(i=0;i<k;i++)
			fprintf(iesire,"%d ",C[i]);
		fclose(iesire);
	}
	void main()
	{
		CITIRE();
		DETECTARE();
		AFISARE();
	}
			
