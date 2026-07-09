#include<stdio.h>
int main(){
    long a,b,n;
    FILE *in,*out;
    in=fopen("euclid.in","r");
    if(fscanf(in,"%ld\n",&n));
    out=fopen("euclid.out","w");
    while(n>0){
       if(fscanf(in,"%ld %ld",&a,&b));
       if(b>a){
               a=a+b;b=a-b;a=a-b;    
       }
       while((a%b!=0)){
             a%=b;a+=b;b=a-b;a=a-b;
       }
       fprintf(out,"%ld\n",b);
       n--;                            
    }
    return 0;
}
