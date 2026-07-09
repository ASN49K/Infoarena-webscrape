#include<iostream.h>
#include <fstream.h>
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);

int main()
 {
long a,b,t,r;
 f>>t;
while (t!=0){
	      f>>a;f>>b;

	      do{ r=a%b;
		  a=b;
		  b=r ;
		 }
	      while(r!=0);
	   g<<a<<"\n";
	   t--;
	   }
   f.close();
   g.close();

      return 0;
	 }



