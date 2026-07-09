#include<fstream>
using namespace std;
int main()
{int a,b,n,R,i;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>n;
for(i=1;i<=n;i++)
   {f>>a>>b;
    do
	{R=a%b;
	 a=b;
	 b=R;}
	while(R!=0);
	g<<a<<endl;}
f.close();
g.close();
return 0;}
