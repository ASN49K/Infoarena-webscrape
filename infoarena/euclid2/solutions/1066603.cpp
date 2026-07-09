#include <cstdio>
int cmmdc (int a, int b)
{
    if(b==0)
        b=a;
    else return cmmdc(b,a%b);
}
int main ()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    int a,b,N;
    scanf("%d",&N);
    while(N)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",cmmdc(a,b));
        N--;
    }
    fclose(stdin);
    fclose(stdout);
}
