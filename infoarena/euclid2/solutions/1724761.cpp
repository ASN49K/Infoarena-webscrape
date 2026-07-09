//Euclid algorithm with repeatedly divisions 

#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return cmmdc(b,a%b);
}

void start(FILE*in,FILE *out)
{
	int nr,a,b;
	fscanf_s(in,"%d",&nr);
	for(int i=0;i<nr;i++)
	{
		fscanf_s(in,"%d %d",&a,&b);
		fprintf_s(out,"%d\n",cmmdc(a,b));

	}

}

int main(int argc,char*argv[])
{
	FILE *in,*out;
	fopen_s(&in,"test.in","r");
	if(in==NULL)
	{
		perror("Error at opening the file for reading.\n");
		exit(1);
	}
	fopen_s(&out,"test.out","w");
	if(out==NULL)
	{
		perror("Error at opening the file for writing.\n");
		exit(2);
	}
	start(in,out);

	return 0;
}