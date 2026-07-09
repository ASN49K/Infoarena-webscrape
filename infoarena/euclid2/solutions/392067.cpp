#include<fstream>
using namespace std;

int main()
{
	int a,b,t,i,x;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>t;
	for (i=1;i<=t;i++)
	{	
		in>>a>>b;
		while (b!=0)
		{
		   x=b;
		   b=a%b;
		   a=x;
		}
		out<<a;
	}
	in.close();
	out.close();	
}
	