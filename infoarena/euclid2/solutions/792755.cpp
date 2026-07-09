#include <cstdio>

using namespace std;

int t,a,b;

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
void citire()
{
    scanf("%d\n",&t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a,b));
    }
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    citire();
    return 0;
}
