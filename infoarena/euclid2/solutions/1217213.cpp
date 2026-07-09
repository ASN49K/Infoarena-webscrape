#include<stdio.h>

int aux,n,x,y;

int cmmdc(int a, int b)
{
	if(b == 0)
	{
        return a;
	}
	else return cmmdc(b, a % b);

}

int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		scanf("%d %d", &x, &y);
		printf("%d \n", cmmdc(x,y));
	}


		return 0;
}
