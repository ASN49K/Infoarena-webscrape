#include <iostream>
#include <fstream>
using namespace std;
long a,b,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   f>>t;
   while(t>0)
	{f>>a>>b;
	while(a*b!=0)
		if(a>b)
		a=a%b;
		else
		b=b%a;
	g<<a+b<<endl;
	t--;
}
   f.close();
   g.close();
   return 0;

}