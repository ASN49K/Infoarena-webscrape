#include <fstream>
using namespace std; 
ifstream f ("euclid.in");
ofstream g ("euclid.out");
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
 while (t!=0)
 {
	 t--;
	 f>>a>>b;
	 euclid(a,b,d);
	 g<<d<<'\n';
 }
 return(0);
}