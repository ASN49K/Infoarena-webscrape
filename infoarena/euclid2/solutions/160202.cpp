#include <stdio.h>
int cmmdc(int,int);
inline void rezolva_test()
{
	int a, b;
	scanf("%d%d\n",&a,&b);
	printf("%d\n",cmmdc(a,b));
}
int cmmdc(int a, int b)
{
	if(a==0) return b;
	if(b==0) return a;
	if(a>b) return cmmdc(a%b, b);
	if(b>a) return cmmdc(a, b%a);
}
int main()
{
	int t;
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	scanf("%d\n",&t);
	for(int i=0;i<t;++i) rezolva_test();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
