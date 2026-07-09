#include <stdio.h>
#include <stdlib.h>

#define i_file "euclid2.in"
#define o_file "euclid2.out"

int gdc(int a, int b)
{
	if (b == 0) return a;
	else return gdc(b, a % b);
}

int main(int argc, char **argv, char **env)
{
	freopen(i_file,"r",stdin);
	freopen(o_file,"w",stdout);
	
	int i;
	scanf("%d",&i);
	while (i--)
	{
		int a[2];
		scanf("%d%d",a,a+1);
		printf("%d\n",gdc(*a,*(a+1)));
	}

	return 0;
}