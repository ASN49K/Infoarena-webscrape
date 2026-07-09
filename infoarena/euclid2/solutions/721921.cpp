#include <cstdio>

inline int gcd(int a,int b)
{
	while (a!=0 && b!=0)
	{
		if(a>b) a=a%b;
		else b=b%a;
	}
	if (a==0) return b; else return a;
	
}
int main()
{
	int a,b;
	int n;
	FILE* in=fopen("euclid2.in","r");
	FILE* out=fopen("euclid2.out","w");
	fscanf(in,"%d",&n);
	for(int i=0;i<n;i++)
	{
		fscanf(in,"%d %d",&a,&b);
		fprintf(out,"%d\n",gcd(a,b));

	}
	fclose(in);
	fclose(out);
	return 0;

}