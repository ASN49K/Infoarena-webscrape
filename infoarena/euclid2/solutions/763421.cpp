#include <fstream>
using namespace std; 
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
void euclid (int a,int b,int &d)
{
	if (b==0)
	{
		d=a;
		return;
	}
	euclid(b,a%b,d);
}
int main ()
{
 int a,b,d,t;
 f>>t;
 while ( t--)
 {

	 f>>a>>b;
	 euclid(a,b,d);
	 g<<d<<'\n';
 }
 return(0);
}