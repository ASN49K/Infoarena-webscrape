#include<fstream>
#include<iostream>
using  namespace std;
int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
	int nrt;
	scanf("%d",&nrt);
	for(int test = 0; test<nrt; test++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int gc=gcd(x,y);
		printf("%d\n",gc);
	}
	return 0;
}
