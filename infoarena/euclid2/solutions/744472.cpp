#include<cstdio>
using namespace std;
FILE *fin=fopen("euclid2.in","r");
FILE *fout=fopen("euclid2.out","w");
int a,b,i,n;
int f(int a,int b)
{
	if(!b) return a;
	else return f(b,a%b);
}
int main()
{
	fscanf(fin,"%d",&n);
	for(i=1;i<=n;++i)
	{
		fscanf(fin,"%d%d",&a,&b);
		f(a,b);
	}
	return 0;
}
