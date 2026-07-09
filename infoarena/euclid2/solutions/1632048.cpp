#include <iostream>
#include <cstdio>

using namespace std;
int cmmdc_euclid(int a,int b)
{
     if (!b) return a;
     return cmmdc_euclid(b,a%b);

}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,t;
    scanf("%d",&t);
    for (int i=1; i<=t; ++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc_euclid(a,b));
    }
}

