#include<stdio.h>

int a,b,n,i;
FILE *fi,*fo;

int main(void){
    fi=fopen("euclid2.in","r");
    fo=fopen("euclid2.out","w");
    
    fscanf(fi,"%d",&n); 
    
    for(i=1;i<=n;i++) {
                       fscanf(fi,"%d%d",&a,&b);
                       while ((a!=0) && (b!=0)) if (a>b) a%=b; else b%=a;
                       fprintf(fo,"%d\n",a+b); 
                      }
    fclose(fi); fclose(fo);
    return 0;
}
