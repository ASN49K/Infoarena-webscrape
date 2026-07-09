#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
    while(b>0)
    {
        int aux=a%b;
        a=b;
        b=aux;
    }
    return a;
}
int test,x,y;

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",cmmdc(x,y));
    }
    return 0;
}
