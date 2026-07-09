#include <iostream>
#include <cstdio>
using namespace std;

int t,n,s,sumxor;



int main()
{
    int i;
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&t);
    while(t)
    {
        scanf("%d",&n);
        sumxor=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s);
            sumxor=sumxor^s;
        }
        if(sumxor) printf("DA\n");
              else printf("NU\n");
        t--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
