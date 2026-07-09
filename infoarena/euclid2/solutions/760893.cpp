#include<fstream>
using namespace std;
int main()
{unsigned int r=0,a=0,t=0,b=0;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
f>>t;
for (int i=1;i<=t;i++)
	{f>>a>>b;
do
{r=a%b;
a=b;
b=r;}
while (r!=0);
	g<<a<<endl;}
	f.close();
	g.close();
return 0;}
