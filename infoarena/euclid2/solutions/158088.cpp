#include <stdio.h>

int euclid(int x, int y)
{
	if (!y)
		return x;
	return euclid(y,x%y);
}

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	
	int t=0,x=0,y=0;
	
	scanf("%d",&t);
	
	while (t)
	{
		t--;
		scanf("%d%d",&x,&y);
		printf("%d\n",euclid(x,y));		
	}
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
