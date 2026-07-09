#include<stdio.h>
long euclid(a,b){
     if((a&b==0)||(b%a==0))
        if(a>b)return b;
        else return a;
     else 
          if(a>b)return euclid(b,a%b);
          else return euclid(a,b%a);     
}
int main(){
    long a,b,n;
    FILE *in,*out;
    in=fopen("euclid.in","r");
    fscanf(in,"%d\n",&n);
    out=fopen("euclid.out","w");
    while(n>0){
               fscanf(in,"%d %d",&a,&b);
               fprintf(out,"%d\n",euclid(a,b));
               n--;                            
    }
    return 0;
}
