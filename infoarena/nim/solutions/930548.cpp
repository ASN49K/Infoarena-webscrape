#include <fstream>
using namespace std;
int main()
{
	ifstream f("nim.in");
	ofstream h("nim.out");
	int t;
	f>>t;
	int n,x;	
	for(int S=0;t;--t,S=0)
	{
		f>>n;
		for(;n;--n)
		{
			f>>x;
			S=S^x;
		}
		if(S)	h<<"DA\n";
		else	h<<"NU\n";
	}
	f.close();
	h.close();
	return 0;
}

