#include <stdio.h>
#include <stdlib.h>
int ** resultMat;
int * seq;
int size=0;
int lcs(int * a, int * b, int la,int lb)
{
	if(la==0 || lb==0)
		return 0;
	if(resultMat[la-1][lb-1]!=-1)
		return resultMat[la-1][lb-1];
	
	int result;
	
	if(a[la-1]==b[lb-1])
	{
		seq[size]=a[la-1];
		size++;
		result=1+lcs(a,b,la-1,lb-1);
	}
	else
	{
		int lcs1=lcs(a,b,la-1,lb);
		int lcs2=lcs(a,b,la,lb-1);
		result=(lcs1>lcs2)?lcs1:lcs2;
	}
	resultMat[la-1][lb-1]=result;
	return result;
}
int ** allocMat(int x,int y)
{
	int ** m= (int **)malloc(x*sizeof(int));
	for(int i=0;i<x;i++)
		m[i]=(int *) malloc(y*sizeof(int));
	return m;
}
void init(int ** mat,int x,int y)
{
	int i,j;
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			mat[i][j]=-1;
}
int main()
{
	FILE * fIn = fopen("cmlsc.in","r+");
	FILE * fOut =fopen("cmlsc.out","w+");
	int sizeS1,sizeS2;
	fscanf(fIn,"%d %d",&sizeS1,&sizeS2);
	int *s1 = (int *)malloc(sizeS1*sizeof(int));
	int *s2 = (int *)malloc(sizeS2*sizeof(int));
	int i;
	for(i=0;i<sizeS1;i++)
		fscanf(fIn,"%d",s1+i);
	for(i=0;i<sizeS2;i++)
		fscanf(fIn,"%d",s2+i);
	resultMat=allocMat(sizeS1,sizeS2);
	init(resultMat,sizeS1,sizeS2);
	seq=(int *) malloc(sizeof(int)*((sizeS1>sizeS2)?sizeS1:sizeS2));
	fprintf(fOut,"%d\n",lcs(s1,s2,sizeS1,sizeS2));
	for(i=size-1;i>=0;i--)
		fprintf(fOut,"%d ",seq[i]);
	fclose(fIn);
	fclose(fOut);
	free(resultMat);
	free(seq);
	return 0;
}