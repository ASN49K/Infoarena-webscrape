//
 

#include <stdio.h>  
int fct(int a,int b)  
{  
     if(!b)  
         return(a);  
     else  
         return fct(b,a%b);  
}  
   
int main()  
{  
     int i,a,b,t;  
     FILE *f1,*f2;  
     f1=fopen("euclid2.in","r");  
     f2=fopen("euclid2.out","w");  
     fscanf(f1,"%d",&t);  
     for(i=1;i<=t;i++)  
     {  
         fscanf(f1,"%d %d",&a,&b);  
         a=fct(a,b);  
         fprintf(f2,"%d\n",a);  
     }  
     fclose(f1);  
     fclose(f2);  
     return 0;  
}  