using namespace std;
#include<cstdio>
#include<cstring>
int main()
{
	int N, T;
	freopen("nim.in","r",stdin); freopen("nim.out","w",stdout);
	scanf("%d",&T);
	int s, x;
	for(;T;--T)
	{
		scanf("%d",&N);
		s = 0;
		for(int i = 0; i < N; ++i)
		{
			scanf("%d",&x);
            s ^= x;
		}
		if( s == 0) printf("NU\n");
		else printf("DA\n");
	}
	return 0;
}
