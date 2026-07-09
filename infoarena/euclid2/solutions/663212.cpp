#include<cstdio>
using namespace std;
int a,b,n;
int cmmdc(int a,int b)
{
	if(b==0) return a;
	return cmmdc(b,a%b);
}
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d\n",&a,&b);
		printf("%d\n",cmmdc(a,b));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
