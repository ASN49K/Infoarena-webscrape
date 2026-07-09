#include <fstream>
using namespace std;

long euclid2(long x, long y)
{

	if(y == 0)
	  return x;
    else
	  return euclid2(y, x%y);		
}

int main()
{
	
	int t;
	long a,b;
	
	ifstream fin("euclid2.in");
	fin >> t;
	
	ofstream fout("euclid2.out");
	while(t--)
	{
	  fin >> a >> b;
	  fout << euclid2(a,b) << '\n';
	}
	
	return 0;
}