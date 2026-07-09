#include <cstdio>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int gcd(int a,int b)
{
    int r;
    if((a-b)*(a-b)==1)return 1;
    while (b){r=a%b;a=b;b=r;}
    return a;
}
int main()
{
    int n,t1,t2;
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        {
            fscanf(f,"%d%d",&t1,&t2);
            fprintf(g,"%d\n",gcd(t1,t2));
        }
    return 0;
}
