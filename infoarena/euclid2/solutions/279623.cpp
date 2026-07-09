#include<fstream>
using namespace std;

int main()
{
	int n, a, b;
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	in>>n;
	for (int i=0;i<n;i++)
	{
		in>>a>>b;
		while (a!=b)
			if (a>b) a-=b;
			else b-=a;
		out<<a<<endl;
	}
	return 0;
}		
	
