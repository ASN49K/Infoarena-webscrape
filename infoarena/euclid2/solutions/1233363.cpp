#include <cstdio>

using namespace std;
int t, a, b, c, i;
int cmmdc(int a, int b)
{
    if(!b) return a;
    else return cmmdc(b, a%b);
}
int main()
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d", &a, &b);
        if(b>a)
        {
            c=a;
            a=b;
            b=c;
        }
        while(b>0)
        {
            c=b;
            b=a%b;
            a=c;
        }
        printf("%d\n", a);
    }
    return 0;
}
