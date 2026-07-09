# include <cstdio>
using namespace std;
int n,a,b,r,i;
int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		r=0;
		scanf("%d%d",&a,&b);
		r=a%b;
		while(r>0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		printf("%d\n",b);
	}
	return 0;
}
