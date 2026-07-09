#include <cstdio>
#include <math.h>
using namespace std;
int cmmdc(int a, int b)
{
    if((!a) || (!b)) return a+b;
    if(a>b) return cmmdc(a%b,b);
    else return cmmdc(a,b%a);
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int a,b,t;
    scanf("%d",&t);
    for(int i = 1; i<=t; i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    fclose(stdin);
    fclose(stdout);
    return 0;
}
