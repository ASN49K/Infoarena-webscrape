#include<cstdio>
using namespace std;
int n,a,b,d;
int div(int a,int b)
{int d;
	if(a%b==0)
	
		return b;
	else
	{ if(a>b)
		{d=a%b;
		a=b;
		b=d;
		return div(a,b);}
		else
		{d=b%a;
		b=a;
		a=d;
		return div(a,b);}
	}
}
int main()
{
	FILE* f=fopen("euclid2.in","r");
	FILE* g=fopen("euclid2.out","w");
	fscanf(f,"%d",&n);
	for(int i=1;i<=n;++i)
	{
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d \n",div(a,b));
	}
}