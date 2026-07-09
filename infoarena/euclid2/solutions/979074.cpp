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
   for(i=1;i<=n;i++)
	{f>>a>>b;
	if(x>y) swap(y,x);
	while(x){
		r=y%x;
		y=x;
		x=r;}
	g<<a+b<<endl;
}
   f.close();
   g.close();
   return 0;

}