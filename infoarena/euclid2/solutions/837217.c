#include <stdio.h>
using namespace std;


long cmmdc(long a, long b)
{
	if(a==0) return b;
	else
	if (b==0) return a;	
	else
	{
	if (a>b) return cmmdc(a%b,b);
		else return cmmdc(a,b%a);
	}
}

int main()
{
	int n,a,b;
	FILE *fin, *fout;
fin=fopen("euclid2.in","r"); 
fout=fopen("euclid2.out","w"); 

fscanf(fin,"%d",&n); 
for (int i=1;i<=n;i++)
{
	fscanf(fin,"%d%d",&a,&b);
	fprintf(fout,"%d\n",cmmdc(a,b));
}
return 0;
}

	
