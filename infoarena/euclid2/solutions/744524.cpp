
#include <cstdio>
#include <fstream>

using namespace std;

static inline int f (int x,int y)
{
	if(x==y)
		return x;
	if(!x)
		return y;
	if(!y)
		return x;
	if((x&1)==0)
	{
		if((y&1)==0)
			return f(x>>1,y>>1)<<1;
		else
			return f(x>>1,y);
	}
	else
		if((y&1)==0)
			return f(x,y>>1);
		else
			if(x>=y)
				return f((x-y)>>1,y);				
	return f((y-x)>>1,x);
}

int main ()
{
	int x,y,n;
	ifstream in ("euclid2.in");
	freopen ("euclid2.out","w",stdout);
	for(in>>n;n;--n)
	{
		in>>x>>y;
		printf("%d\n",f(x,y));
	}
	return 0;
}
