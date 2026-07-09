#include <iostream.h>
#include <fstream.h>
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
long a,b,T,i;
int  r;
int main()
{
 f>>T;
 for (i=1;i<=T;i++)
     { f>>a>>b;
      do{
	 r=a%b;
	 a=b;
	 b=r;
	 }while (r!=0);
      g>>a;
      };
 f.close();
 g.close();
 return 0;
}