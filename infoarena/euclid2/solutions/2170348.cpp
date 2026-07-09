#include <iostream>
#include <stdio.h>

using namespace std;

int cmmdc(int a,int b)

{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;

    }
    return a;

}

int main()
{


    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out","w", stdout);
    int n, a, b, c, i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        c=cmmdc(a,b);
        printf("%d", c);
        printf("\n");
    }




    return 0;
}
