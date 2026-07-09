#include <iostream>
#include <fstream>
using namespace std;

int main()
{ long T,a,b;
	fstream f("D:\\euclid2.in",ios::in);
	fstream g("D:\\euclid2.out",ios::out);
	f>>T;
	for(int i=1;i<=T;i++)
	{ f>>a>>b;
	  while(a!=b)
		  if(a>b)
			  a=a-b;
		  else
			  b=b-a;
	 g<<a<<endl;
	}
return 0 ;}
