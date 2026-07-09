#include<stdio.h>


int main()
{
	FILE *in;
	FILE *out;
	int M,N;
	int A[1024], B[1024], C[1024];
	int i,j,k;
	int max;
	int lungime = 0;
	
	
	in  = fopen("cmlsc.in","r");
	out = fopen("cmlsc.out","w");
	
	fscanf(in,"%d %d",&M,&N);
	//printf("%d %d\n",M,N);
	
	for(i = 0;i<M;i++)
		fscanf(in,"%d",&A[i]);
	for(j = 0;j<N;j++)
		fscanf(in,"%d",&B[j]);
	
	int x = 0;
	for(i = 0; i < M; i++)
	{
		for(j = x;j < N; j++)
			if(A[i]==B[j])
				{
					C[k] = A[i];
					k++;
					x = j;
				}
		if(k>max)
			max = k;
	}
	
	
/*	for(k = 0;k<max;k++)
		printf("%d ",C[k]);
	printf("\n%d\n",max);	
	for(i = 0;i<M;i++)
		printf("%d ",A[i]);
	for(j = 0;j<N;j++)
		printf("%d ",B[j]);
		*/
	
	fprintf(out,"%d\n",max);
	for (k = 0; k < max; k++)
		fprintf(out,"%d ",C[k]);
	
	close(in);
	close(out);
	return 0;
}
