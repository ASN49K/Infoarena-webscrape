#include<stdio.h>
using namespace std;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int t,i,n,a,rez;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        rez=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            rez=rez xor a;
        }
        if(rez)
            printf("DA\n");
        else
            printf("NU\n");
    }
    return 0;
}
