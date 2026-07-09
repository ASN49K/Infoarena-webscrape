#include <iostream>
#include <fstream>
using namespace std;
int eucl(int a,int b)
{
	if(!b) return a;
	else return eucl(b,a%b);
}
int main ()
{
	int a,b,T;
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&T);
	while (T)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",eucl(a,b));
		T--;
	}
	return 0;
}