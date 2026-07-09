#include <fstream>
#define INFILE "nim.in"
#define OUTFILE "nim.out"
using namespace std;
int main()
{
	int t;
	ifstream fin(INFILE);
	ofstream fout(OUTFILE);
	fin >> t;
	int n, x, sum;
	while (t){
		--t;
		fin >> n;
		sum = 0;
		for (int i = 0; i < n; ++i){
			fin >> x;
			sum ^= x;
		}
		if (sum > 0) 
			fout << "DA\n"; 
		else
			fout << "NU\n";
	}
	fin.close();
	fout.close();
}