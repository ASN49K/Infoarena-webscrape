#include<fstream>
using namespace std;

int main()
{
	int n, a, b,t;
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	in>>n;
	for (int i=0;i<n;i++)
	{
		in>>a>>b;
		while (b!=0) {
			t=b;
			n=a%b;
			a=t;
			}
		out<<a<<endl;
	}
	return 0;
}		
	
