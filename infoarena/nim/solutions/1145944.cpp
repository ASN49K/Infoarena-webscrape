#include<fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
	int t,n,m,s;
	in>>t;
	while (t--)
	{
		s=0;
		in>>n;
		while(n--)
		{
			in>>m;
			s^=m;
		}
		if(s) out<<"DA\n";
		else out<<"NU\n";
	}
}