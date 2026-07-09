#include<stdio.h>
FILE *in,*out;
int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}
int a,b,n;
int main(){
    in=fopen("euclid.in","r");
    out=fopen("euclid.out","w");
    fscanf(in,"%d",&n);
    while(n>0){
       fscanf(in,"%d %d",&a,&b);
       /*if(b>a){
               a=a+b;b=a-b;a=a-b;    
       }
       while((a%b!=0)){
             a%=b;a+=b;b=a-b;a=a-b;
       }*/
       fprintf(out,"%d\n",gcd(a, b));
       n--;                    
    }
    return 0;
}
