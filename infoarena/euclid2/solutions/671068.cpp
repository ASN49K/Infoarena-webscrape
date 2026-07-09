#include<fstream>
using namespace std;
int main()
{int a,b,n,i,R;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
   {f>>a>>b;
    do
	{R=a%b;
	 a=b;
	 b=R;}
	g<<a<<'\n';}
f.close();
g.close();
return 0;}
