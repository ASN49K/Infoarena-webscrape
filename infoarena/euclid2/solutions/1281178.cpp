#include <stdio.h>
using namespace std;
int main()
{
    int n;
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d",&n);
    for(int a=1;a<=n;a++)
    {
        unsigned long long x,y,c;
        scanf("%llu %llu",&x,&y);
        while(y)
        {
            c=x%y;
            x=y;
            y=c;
        }
        printf("%llu\n",x);
    }
}
