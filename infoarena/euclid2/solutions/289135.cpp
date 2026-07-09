//#include<fstream.h>
#include<fstream>
using namespace std;

int main()
{
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	int a,b,r,n;
	in>>n;
	for (int i=0;i<n;i++) {
		in>>a>>b;
		while (b!=0) {
			r=a%b;
			a=b;
			b=r;
		}
		out<<a<<endl;
	}
	in.close();
	out.close();
	return 0;
}