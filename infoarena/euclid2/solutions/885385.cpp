#include <cstdio>

using namespace std;
int i,aux,n,b,k,j,p,a,m,s;

int euclid(int x,int y)
{
    int rest;
    while (y) {
        rest = x % y;
        x= y;
        y = rest;
    }
    return x;
}

int main()
{
    freopen ("euclid2.in","r",stdin);
    freopen ("euclid2.out","w",stdout);

    scanf("%d",&n);
   // printf("%d\n",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        aux=euclid(a,b);
        printf("%d\n",aux);
    }

}
