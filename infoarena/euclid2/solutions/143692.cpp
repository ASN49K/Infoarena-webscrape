#include <fstream.h>

 long a,b,d;  
 int main()  
 {  
     ifstream f("euclid2.in");  
     ofstream g("euclid2.out");  
    f>>a>>b;  
    do  
     {  
         d=a%b;  
         a=b;  
         b=d;  
     }  
     while(d);  
     g<<a;  
     return 0;  
 }
