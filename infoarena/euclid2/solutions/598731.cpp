#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
	int nr,a,b,r;
	
	fin >> nr;
	
	for(; nr > 0; nr--)
	{
		fin >> a >> b;
		
		while(b > 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		
		fout << a << '\n';
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
