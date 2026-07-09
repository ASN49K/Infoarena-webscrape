#include <cstdio>
using namespace std;
int n,m,i,j,x,y;
int cmmdc(int a,int b)
{
    int aux;
    while(a!=0)
    {
        if(a<b)
        {
            aux=a;
            a=b;
            b=aux;
        }
        a=a%b;
    }
    return b;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
