#include <stdio.h>
#include <stdlib.h>
int cmmdc(int a,int b){
    if(b==0){
        return a;
    }
    else {
        return cmmdc(b,a%b);
    }
}
int main()
{
    FILE *f=fopen("euclid2.in","r");
    FILE *g=fopen("euclid2.out","w");
    int i,t,a,b;
    fscanf(f,"%d",&t);
    for(i=1;i<=t;i++){
        fscanf(f,"%d %d",&a,&b);
        fprintf(g,"%d\n",cmmdc(a,b));
    }
    fclose(f);
    fclose(g);
    return 0;

}
