#include<fstream.h>
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 int euclid(int a,int b)
 {  if(a==0) return b;
   while(b!=0)
   if(a>b) a=a-b;
     else b=b-a;
    return a; 
       }
 int main(int a ,int b)
 { f>>a>>b;
   //euclid(a,b);
   g<<euclid(a,b);
   return 0;
      }
      
