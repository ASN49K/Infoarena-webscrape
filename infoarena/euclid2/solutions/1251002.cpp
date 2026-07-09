# include <cstdio>

using namespace std;

int n;
int a,b;

int cmmdc(int a, int b)
{
    if(a==0) return b;
    else cmmdc(b, a%b);
}

int main()
{
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);

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
