#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define Max 10099
int t;
char tmp[11*Max+10];

void Solve()
{
    int n;
    unsigned long long x=0;
    scanf("%d \n", &n);
    fgets(tmp, 200000, stdin);
    char *p = tmp;
    for (int i=1; i<=n; i++)
    {
        int val = 0;
        for (; '0' <= *p && *p <= '9'; p++)
        {
            val = val * 10 + *p - '0';
        }
        for (; '0' > *p || *p > '9'; p++);
        x=x^val;
    }
    if (x>0)printf("%s \n","DA");
    else printf("%s \n","NU");
}
int main()
{
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);
	scanf("%d", &t);
	for(int i=1;i<=t;i++)Solve();
	return 0;
}
