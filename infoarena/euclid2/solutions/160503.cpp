#include<stdio.h>

int cmmdc(int a,int b)
{
    if(!b) return a;
    return  cmmdc(b,a%b);
}

int main()
{
    int a,b,t;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",cmmdc(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
