//#include <iostream>
#include <fstream.h>
int cmmdc (long a , long b);
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
 { long nr1, nr2 , n,i=0;
   f>>n;
   while(i<n)
   {f>>nr1;f>>nr2;
    g<<cmmdc(nr1,nr2);
	g<<"\n";i++;}
   f.close();
   g.close();
   return 0;
 }
 int cmmdc (long a , long b)
 { if(b==0)
		return a;
   else
		return cmmdc(b,a%b);
 }
 
 
 