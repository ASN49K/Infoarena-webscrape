#include <cstdio>
using namespace std;

int t,n,a,b;
int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);b=0;
         for(;n;--n) scanf("%d",&a), b^=a;

         if(!b) printf("NU\n");
         else printf("DA\n");
    }

    return 0;
}
