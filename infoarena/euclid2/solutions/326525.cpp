#include<stdio.h>   
FILE *f,*g;  
int main()  
  {  
    long int t,a,b,r,i;  
    f=fopen("euclid.in","r");  
    g=fopen("euclid.out","w");  
    fscanf(f,"%ld\n",&t);  
   for(i=0;i<t;i++)  
   {  
     fscanf(f,"%ld %ld",&a,&b);  
     while(b)  
      {  
        r=a%b;  
        a=b;  
        b=r;  
      }  
      fprintf(g,"%ld\n",a);  
   }  
    return 0;  
  } 

