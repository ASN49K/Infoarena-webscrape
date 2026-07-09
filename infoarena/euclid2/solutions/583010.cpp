#include<fstream>
using namespace std;
int t,a,b;
int main()
{
	int i,r;
	ifstream f("euclid2.in");
	ofstream fout("euclid2.out");
	f>>t;
	for(i=0;i<t;i++)
	{
		f>>a>>b;
		r=0;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<"\n";
	}
	f.close();
	fout.close();
	return 0;
}
