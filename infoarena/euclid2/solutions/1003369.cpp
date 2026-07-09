#include <cstdio>
using namespace std;
FILE *f;
int n,i,crt,prev,Max,b,mb,mf;
int main()
{
	f=fopen("ssm.in","r");
	fscanf(f,"%d%d",&n,&prev);
	Max=prev;
	b=1;mb=1;mf=1;
	for (i=2;i<=n;i++)
	{
		fscanf(f,"%d",&crt);
		if (prev>=0)
			crt+=prev;
		else
			b=i;
		if (crt>Max)
		{
			Max=crt;
			mb=b;
			mf=i;
		}
		prev=crt;
	}
	fclose(f);
	f=fopen("ssm.out","w");
	fprintf(f,"%d %d %d\n",Max,mb,mf);
	fclose(f);
	return 0;
}
