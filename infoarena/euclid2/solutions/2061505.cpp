#include <stdio.h>
int A,B,T;
int cmmdc(int A,int B)
{
    if (!B) return A;
    if (A>B) return cmmdc(A-B,B);
    else return cmmdc(A,B-A);
}
int main()
{
    freopen("cmmdc.in","r",stdin);
    freopen("cmmdc.out","w",stdout);
    for (scanf("%d",&T);T;T--)
    {
        scanf("%d%d",&A,&B);
        printf("%d\n",cmmdc(A,B));
    }
}
