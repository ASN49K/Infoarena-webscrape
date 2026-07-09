#include <stdio.h>
using namespace std;
FILE *f=fopen("euclid2.in","r"),
    *g=fopen("euclid2.out","w");
int a,b,n,r,i;
int main()
{
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++){
        fscanf(f,"%d %d",&a,&b);
        while(b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        fprintf(g,"%d\n",a);
    }
    return 0;
}
