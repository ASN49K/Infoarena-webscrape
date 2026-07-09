#include<cstdio>

int eu(int a, int b)
{
    if (!b) 
	return a;
    return eu(b, a % b);
}

int main()
{
	int n,m,t;
	freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	scanf("%d",&t);
	for( ; t; t--)
	{	
	  scanf("%d %d",&n,&m);
	  printf("%d\n",eu(n,m));
	}  
	
	return 0;
}
