#include <cstdio>
using namespace std;
int T,i,a,b,aux;
int cmmdc(int a,int b)
{
    while(a%b!=0)
    {
        aux=a%b;
        a=b;
        b=aux;
    }
    return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}

