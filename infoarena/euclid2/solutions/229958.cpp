#include<fstream>
using namespace std;
int main()
{
	int a,b,n;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	in>>n;
	while(n--)
	{
		in>>a>>b;
		while(a!=b)
		{
			if (a>b) a=a-b;
			if (b>a) b=b-a;
		}
		out<<a<<"\n";
	}
	in.close();
	out.close();
	return 0;
}
