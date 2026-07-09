#include <stdio.h>  
int fct(int a,int b)  
{if(!b)  
return(a);  
else  
return fct(b,a%b);}  
   
int main()  
{  
     int i,a,b,t;  
     FILE *fi,*fo;  
     fi=fopen("euclid2.in","r");  
     fo=fopen("euclid2.out","w");  
     fscanf(fi,"%d",&t);  
     for(i=1;i<=t;i++)  
     {  
         fscanf(fi,"%d %d",&a,&b);  
         a=fct(a,b);  
         fprintf(fo,"%d\n",a);  
     }  
     fclose(fi);  
     fclose(fo);  
     return 0;  
}  