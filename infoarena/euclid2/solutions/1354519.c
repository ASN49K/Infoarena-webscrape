#include<stdio.h>
int main(){
    long int a,b,n,c;
    FILE *in,*out;
    in=fopen("euclid.in","r");
    if(fscanf(in,"%ld\n",&n));
    out=fopen("euclid.out","w");
    while(n>0){
       if(fscanf(in,"%ld %ld",&a,&b));
       if(b>a){
             c=a;a=b;b=c;    
       }
       while((a%b!=0)){
             a%=b;c=a;a=b;b=c;
       }
       fprintf(out,"%ld\n",b);
       n--;                            
    }
    return 0;
}
