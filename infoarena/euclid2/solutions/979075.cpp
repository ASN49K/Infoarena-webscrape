#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
long a,b,i,t,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
   f>>t;
   for(i=1;i<=t;i++)
	{f>>a>>b;
	if(a>b) swap(a,b);
	while(a){
		r=b%a;
		b=a;
		a=r;}
	g<<a+b<<endl;
}
   f.close();
   g.close();
   return 0;

}