#include<fstream>
using namespace std;
int main()
{ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,r;
f>>t;
for(;t;--t)
{f>>a>>b;
 while(b)
   {r=a%b;
	a=b;
	b=r;}
 g<<a<<"\n";
}
return 0;
}
