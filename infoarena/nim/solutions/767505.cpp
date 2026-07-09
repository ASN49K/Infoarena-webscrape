#include<fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int t,i,s,s1,x,n;
int main()
{f>>t;
for(s1=1;s1<=t;++s1)
{
f>>n;
s=0;
for(i=1;i<=n;++i)
	f>>x,s=s xor x;
if(s)
	g<<"DA\n";
else
	g<<"NU\n";
}
return 0;
}