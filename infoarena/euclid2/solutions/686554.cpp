#include<fstream>
using namespace std;
int main()
{int a,b,n,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(;n;--n)
	{f>>a>>b;
     while(b)
	 {r=a%b;
	 a=b;
	 b=r;}
	 g<<a<<"\n";}
}