#include <stdio.h>
int cmmdc(int a, int b)
{
    while(a&&b)
        if(a>b)
            a%=b;
        else b%=a;
    if(b)
        return b;
    else
        return a;
}
int main()
{
    FILE *f1 = fopen("euclid2.in","r"), *f2 = fopen("euclid2.out","w");
    int n, a, b, i;
    fscanf(f1,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(f1,"%d%d",&a,&b);
        fprintf(f2,"%d\n",cmmdc(a,b));
    }
    return 0;
}
