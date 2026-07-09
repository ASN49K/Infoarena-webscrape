#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int gcd_div(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return gcd_div(b,a%b);
}

void start()
{
		FILE *fdIn,*fdOut;
		int nr,i,a,b,result;
		fopen_s(&fdIn,"input.txt","r");
		fopen_s(&fdOut,"output.txt","w");
		if(fdIn==NULL)
		{
			perror("Error at opening the file.\n");
			exit(2);
		}
		if(fdOut==NULL)
		{
			perror("Error at creating the destination file.");
			exit(2);
		}
		if(fscanf_s(fdIn,"%d",&nr)!=1)
		{
			perror("Error at reading from the file.");
			exit(2);
		}

		for(i=0;i<nr;i++)
		{
			if(fscanf_s(fdIn,"%d %d",&a,&b)!=2)
			{
				perror("Error at reading the values from the file.");
				exit(2);
			}
			result=gcd_div(a,b);
			printf("gcd(%d,%d)=%d.\n",a,b,result);
			if(fprintf(fdOut,"%d\n",result)<0)
			{
				perror("Error at writing to the file.\n");
				exit(2);
			}
		}
}

int main(int argc,char*argv[])
{

	start();

	return 0;
}