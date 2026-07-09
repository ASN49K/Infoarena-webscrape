#include <cstdio>
using namespace std;

int cmmdc(int a, int b)
{
    while(b)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int n;
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d\n %d\n",&a,&b);
        printf("%d",cmmdc(a,b));
    }
    return 0;
}
