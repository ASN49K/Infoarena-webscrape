#include <cstdio>

FILE*f=fopen("euclid2.in","r");
FILE*h=fopen("euclid2.out","w");

int main()
{
    int n;
    fscanf(f,"%d",&n);
    for ( int i=1;i<=n;++i ){
        int a,b;
        fscanf(f,"%d%d",&a,&b);
        while ( b ){
            int r=a%b;
            a=b;
            b=r;
        }
        fprintf(h,"%d\n",a);
    }
    return 0;
}
