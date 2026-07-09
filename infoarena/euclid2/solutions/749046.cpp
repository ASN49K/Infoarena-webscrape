#include <stdio.h>
#include <string>

using namespace std;
int cmmdc(int x, int y)
{
   if (!y) return x;
   return cmmdc(y, x%y);
}


int main()
{

    int n,a,b,i;
    freopen("scmax.in","f1",stdin);
    freopen("scmax.out","f2",stdout);
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a,b));
    }




    return 0;
}
