#include<stdio.h>
int t,a,b,i,r;
int main()
{
    freopen("euclid2.in","rt",stdin);
    freopen("euclid2.out","wt",stdout);
    scanf("%d",&t);
    for (i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        while(b){r=a%b; a=b; b=r;}
        printf("%d\n",a);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
