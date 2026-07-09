   #include <iostream.h>    
   #include <fstream.h>    
       
   int main()    
       
    {    
    fstream f1("euclid2.in",ios::in);    
     fstream f2("euclid2.out",ios::out);    
       
    long t,a,b,r,i;    
     
  f1 >> t;  
  for(i=1;i<=t;i++)  
  {  
     
  f1 >> a;    
  f1 >> b;    
     
   do{    
        r=a%b;    
       a=b;    
       b=r;    
        }while(r!=0);    
   f2 << a;    
   }   
   f1.close();    
   f2.close();    
   return 0;    
   }    
