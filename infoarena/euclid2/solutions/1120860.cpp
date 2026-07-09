#include<fstream>
using namespace std;
ifstream f ("euclid2.in");
ofstream g ("euclid2.out");

int main()
{
int t,a,b,k=0;
f>>t;
while(t!=0)
	{
		f>>a>>b;
		while(b!=0)
			{
				k=b;
				b=a%b;
				a=k;
			}
		g<<a<<"\n";
	t--;
	}
f.close();
g.close();
return 0;
}