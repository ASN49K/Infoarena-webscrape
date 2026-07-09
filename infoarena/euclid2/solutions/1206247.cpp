#include<cstdio>
using namespace std;
int n,a,b;
int cmmdc(int A, int B)
{
    int R;
    while (B)
        R=A%B, A=B, B=R;
    return A;
}
int main()
{
    int i;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;++i)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    return 0;
}
