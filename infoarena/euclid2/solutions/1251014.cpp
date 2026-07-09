# include <cstdio>

using namespace std;

int n;
int a,b;

int cmmdc(int a, int b)
{
    if(b==0) return a;
    else cmmdc(b, a%b);
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

    scanf("%d\n", &n);
    while(n--)
    {
        scanf("%d %d\n", &a, &b);
        printf("%d\n", cmmdc(a,b));
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
