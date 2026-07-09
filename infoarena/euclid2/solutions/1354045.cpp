#include<stdio.h>
int main(){
    int a,b,n;
    FILE *in,*out;
    in=fopen("euclid.in","r");
    fscanf(in,"%d",&n);
    out=fopen("euclid.out","w");
    while(n>0){
       fscanf(in,"%d %d",&a,&b);
       if(b>a){
               a=a+b;b=a-b;a=a-b;    
       }
       while((a%b!=0)){
             a%=b;a+=b;b=a-b;a=a-b;
       }
       fprintf(out,"%d\n",b);
       n--;                    
    }
    return 0;
}
