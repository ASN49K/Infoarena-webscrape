#include <fstream>

using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int a,b,r,n;
	fin>> n;
	while(n!=0)
	{
	fin >> a >> b;
	
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	fout<< a << '\n';
	n--;
   }
	return 0;
}
