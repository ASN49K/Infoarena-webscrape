#include <stdio.h>
#define N 1024
#define debug 0
int a[N], b[N], c[N];
int main()
{
    FILE *f1, *f2;
    if(debug==1){
        f1=fopen(stdin,"r");
        f2=fopen(stdout,"w");
    } else {
        f1=fopen("cmlsc.in","r");
        f2=fopen("cmlsc.out","w");
    }
    int A, B, C=0, i, j;

    fscanf(f1,"%d%d",&A,&B);
    for(i=0;i<A;i++) fscanf(f1,"%d",&a[i]);
    for(i=0;i<B;i++) fscanf(f1,"%d",&b[i]);
    i=j=0;

    while(i<A){
        j=0;
        while(j<B && a[i]!=b[j]) j++;
        if(a[i]==b[j]){
            c[C]=a[i];
            C++;
        }
        i++;
    }

    fprintf(f2,"%d\n",C);
    for(i=0;i<C;i++)
        fprintf(f2,"%d ",c[i]);
    return 0;
}
