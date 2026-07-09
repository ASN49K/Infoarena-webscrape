#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int t,a,b;
int euclid(int a, int b)
{
if(b==0)
	return a;
else return euclid(b,a%b);	
}
int main()
{
in>>t;
for(int i=1;i<=t;i++)
	{
		in>>a>>b;
		out<<euclid(a,b)<<'\n';
	}
out.close();
return 0;
}