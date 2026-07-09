#include<cstdio>

int a,b,r,t;

void cmmdc()
{
	int w=a;
	int q=b;
	while (q>0)
	{
		r=w%q;
		w=q;
		q=r;
	}
	printf("%d\n", w);
}

void citire()
{
    freopen("euclid2.in","r",stdin);
    for (int p=scanf("%d", &t); p; p--)
    {
        scanf("%d%d", &a, &b);
        cmmdc();
    }
    fclose(stdin);
}

int main()
{
	freopen("euclid2.out","w",stdout);
	citire();
	fclose(stdout);
	return 0;
}
