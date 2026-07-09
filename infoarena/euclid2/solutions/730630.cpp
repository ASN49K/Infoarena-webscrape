
#include <cstdio>
#include <fstream>

using namespace std;

inline int cmmdc (int x,int y)
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
			return cmmdc(x>>1,y>>1)<<1;
		else
			return cmmdc(x>>1,y);
	}
	else
		if((y&1)==0)
			return cmmdc(x,y>>1);
		else
			if(x>=y)
				return cmmdc((x-y)>>1,y);
			else
				return cmmdc((y-x)>>1,x);
}

int main ()
{
	freopen ("euclid2.out","w",stdout);
	ifstream in ("euclid2.in");
	int n;
	in>>n;
	for(int x,y;n;--n)
	{
		in>>x>>y;
		printf("%d\n",cmmdc(x,y));
	}
	return 0;
}
