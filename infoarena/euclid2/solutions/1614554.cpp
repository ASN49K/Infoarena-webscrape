#include <iostream>
#include <fstream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out ("euclid2.out");

int T,a,b;

int main()
{
	in>>T;
	for(int i=1;i<=T;i++)
	{
		in>>a>>b;
		while(a!=0&&b!=0)
			if(a>b)
				a=a-(a/b)*b;
			else
				b=b-(b/a)*a;
		if(a!=0)
			out<<a<<endl;
		else
			out<<b<<endl;
	}
	return 0;
}