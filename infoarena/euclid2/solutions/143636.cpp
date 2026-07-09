#include<fstream.h>
 ifstream f("euclid2.in");
 ofstream g("euclid2.out");
 
  int euclid(int a,int b)
 {   if(b==0) return a;
       else return euclid(b,a%b);
 }
 int main(int a ,int b)
 { f>>a>>b;
    g<<euclid(a,b);
   return 0;
      }
