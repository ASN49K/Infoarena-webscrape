#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	int t,numPiles;
	fstream fin("nim.in", fstream::in);
	fstream fout("nim.out", fstream::out);
	
	fin >> t;
	//cout << t << endl;
	
	for (int i=0; i<t; ++i)
	{
		int xor_sum=0, pile;
		fin >> numPiles;
		
		for (int j=0; j<numPiles; ++j)
		{
			fin >> pile;
			xor_sum ^= pile;
		}
		
		if (xor_sum)
			fout << "DA\n";
		else
			fout << "NU\n";
	}
	
	fin.close();
	fout.close();
	return 0;
}
