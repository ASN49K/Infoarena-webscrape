#include<fstream> 
using namespace std;
int main()
{int a,b,i,t,r;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
f>>t;
for(i=1;i<=t;i++)
{	f>>a>>b;
while(b!=0)
	{r=a%b;
a=b;
b=r;}
g<<a<<endl;}
g<<endl;
return 0;
}