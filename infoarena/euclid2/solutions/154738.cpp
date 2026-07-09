#include <stdio.h>
#define MAX 2000000000

long long a,b,c,x,y,k1,k2,d,t;

void gcd(long long a1, long long b1, long long &x, long long &y, long long &d)
{
	long long x0,y0;
	if (b1==0)
		{
			x=1;
			y=0;
			d=a1;
		}
		else
		{
			gcd(b1,a1%b1,x0,y0,d);
			x=y0;
			y=x0 - (a1/b1)*y0;
		}
}

void solve()
{

	scanf("%lld %lld %lld",&a,&b,&c);

	gcd(a,b,x,y,d);

	if (c%d) {printf("0 0\n");return;}
        printf("%lld %lld\n",x*(c/d),y*(c/d));return;
	k1=b/x;
	k2=a/y;

	x=x*(c/d);
	y=y*(c/d);

	if (x>MAX) {
		t= (x - MAX) / k1 + 1;
		y=y+t*k2;
		x=x - t * k1;
		printf("%lld %lld\n",x,y);
		return;
		}
		else
		if (y>MAX)
			{
			t= ( y- MAX) / k2 + 1;
			y=y-t*k2;
			x=x+t*k1;
			printf("%lld %lld\n",x,y);
			return;
			}
			else 
				if (x<-MAX)
				{
				t= (-x - MAX) / k1 + 1;
				x=x+t*k1;
				y=y-t*k2;
				printf("%lld %lld\n",x,y);
				return;
				}
				else 
				if (y<-MAX)
				{
				t= (-y - MAX) / k2 + 1;
				y=y+t*k2;
				x=x-t*k1;
				printf("%lld %lld\n",x,y);
				return;
				}
	printf("%lld %lld\n",x,y);
	return;
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);

	long int T;

	scanf("%ld",&T);

	for (;T;T--)
	{

        scanf("%lld %lld",&a,&b);

        gcd(a,b,x,y,d);
        printf("%lld\n",d);
	}
        return 0;
}
