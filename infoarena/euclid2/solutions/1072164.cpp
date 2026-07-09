#include<fstream>
using namespace std;
int main()
{int a,b,t;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>t;
while(t>0)
{f>>a>>b;t--;
while(a!=b)
	if(a>b)
	a=a-b;
else 
	b=b-a;
if(a==1)
g<<1;
else
g<<a<<endl;}
return 0;

}