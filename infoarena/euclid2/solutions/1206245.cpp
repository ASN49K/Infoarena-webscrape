#include<cstdio>
using namespace std;
int n,a,b;
int cmmdc(int A, int B)
{
    if (B==0) return A;
    else return cmmdc(B,A%B);
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
