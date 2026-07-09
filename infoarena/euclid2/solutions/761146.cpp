#include<fstream>
using namespace std;
int main()
{unsigned int r=0,a=0,t=0,b=0;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
f>>t;
for (register unsigned int i=1;i<=t;i++)
	{f>>a;
	f>>b;
do
{r=a%b;
a=b;
b=r;}
while (r!=0);	
	g<<a<<'\n';}
	f.close();
	g.close();
return 0;}
