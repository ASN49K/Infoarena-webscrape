#include <stdio.h>
using namespace std;
int T,i,x,y;
int cmmdc(long int a,long int b)
{if(b==0) return a;
return cmmdc(b, a % b);
}
int main()
{
freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%d", &T);
for(i=1;i<=T;i++)
{scanf("%d %d", &x, &x);
        printf("%d\n", cmmdc(x, y));


}

    return 0;
}
