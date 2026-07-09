//Euclid algorithm based on subtractions
#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	if(a>b)
	{
		return cmmdc(a-b,b);
	}
	else{
		return cmmdc(a,b-a);
	}
}


void start(FILE*in,FILE*out)
{
	int nr,a,b,result;
	fscanf_s(in,"%d",&nr);
	for(int i=0;i<nr;i++)
	{
		fscanf_s(in,"%d %d",&a,&b);
		result=cmmdc(a,b);
		fprintf_s(out,"%d\n",result);
	}
}

int main(int argc,char*argv[])
{
	FILE *in,*out;
	fopen_s(&in,"test.in","r");
	if(in==NULL)
	{
		perror("Error at reading the file.\n");
		exit(1);
	}
	fopen_s(&out,"test.out","w");
	if(out==NULL)
	{
		perror("Error at creating the file.\n");
		exit(2);
	}
	start(in,out);

	return 0;
}
