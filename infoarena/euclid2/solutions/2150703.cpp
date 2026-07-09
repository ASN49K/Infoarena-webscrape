#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
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
