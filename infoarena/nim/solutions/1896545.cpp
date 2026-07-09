#include <iostream>
#include <cstdio>
using namespace std;
long long f,n,sum=0,k;
void citire()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&f);
        sum=0;
        for(int j=1; j<=f; j++)
        {
            scanf("%d",&k);
            sum=sum^k;
        }
        if(sum)
            printf("DA");
        else
            printf("NU");
            printf("\n");
    }
}
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    citire();
    return 0;
}
