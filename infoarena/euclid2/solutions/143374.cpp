#include <iostream.h>
#include <fstream.h>

void main()
{
 fstream f1("euclid2.in",ios::in);
 fstream f2("euclid2.out",ios::out);


 int a,b,c;



 f1 >> a;
 f1 >> b;

 while(b){
	  c=a%b;
	  a=b;
	  b=c;
	  }
 f2 << a;

 f1.close();
 f2.close();
}
