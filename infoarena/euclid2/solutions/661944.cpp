#include<cstdio>
using namespace std;

const char in[]="euclid2.in";
const char out[]="euclid2.out";

int a, b, T;

int euclid(int a, int b)
	{
		if(!b)return a;
		return euclid(b, a%b);
}
		
		
		

int main()
	{
		freopen(in,"r",stdin);
		freopen(out,"w",stdout);
		
		scanf("%d", &T);
		
		for(;T--;)
		{
			scanf("%d %d", &a, &b);
			printf("%d\n", euclid(a, b));
		}
		
		return 0;
}