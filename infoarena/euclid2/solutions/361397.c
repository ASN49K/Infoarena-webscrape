#include<stdio.h>
main()
{
int t,a,b,i,r,s,cmmdc;
FILE* f=fopen("euclid2.in","r");
FILE* g=fopen("euclid2.out","w");
fscanf(f,"%d",&t);
for(i=1;i<=t;i++)
 { fscanf(f,"%d %d",&a,&b); 
   s=0;
   do{
       r=a%b;
       if(r==0){cmmdc=b; s++;}
       else { a=b;b=r;}
      }while(s==0);
    fprintf(g,"%d\n",cmmdc);
 }
fclose(f);
fclose(g);
return 0;
}
