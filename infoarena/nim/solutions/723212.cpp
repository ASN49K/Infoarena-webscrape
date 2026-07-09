#include <cstdio>
using namespace std;
int main()
{ int i,t,n,j,xo,x;
freopen("nim.out","w",stdout);
freopen("nim.in","r",stdin); scanf("%d\n",&t);
for(i=1;i<=t;++i)
    {
    scanf("%d\n",&n);
    xo=0;
    for(j=1;j<=n;++j)
        {
        scanf("%d ",&x);
        xo=xo^x;
        }
    if(xo==0)printf("NU\n")
        else printf("DA\n");
    }
fclose(stdin);
fclose(stdout);
return 0;
}
