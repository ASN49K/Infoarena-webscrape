#include<fstream>
using namespace std;
int main()
{
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,i,a,b;
cin>>n;
for(i=0;i<n;i++)
{
	f>>a>>b;
	int c;
	while(b)
	{
	c=a%b;
	a=b;
	b=c;
	}
	g<<a<<"\n";
}
return 0;
}