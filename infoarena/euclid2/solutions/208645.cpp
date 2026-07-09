#include<fstream.h>

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{
	long long a, b;
	long T, r, i;	

	fin >> T;
	
	while( (fin >> a) && (fin >> b) )
	{
		r = a % b;
		while(r)
		{
			a = b;
			b = r;
			r = a % b;
		}

		fout << b << endl;
	}
	
	fout.close();
 return 0;
}