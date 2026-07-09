#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin, *fout;
    fin = fopen("euclid2.in","r");
    fout = fopen("euclid2.out","w");
    int a,b,t,i;
    fscanf("%d",&t);
    for(i=1;i<=t;i++){
    fscanf(fin,"%d%d",&a,&b);
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }
    fprintf(fout,"%d",a);
    }
    return 0;
}
