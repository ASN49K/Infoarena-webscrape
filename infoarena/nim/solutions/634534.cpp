#include <fstream>
using namespace std;

int main()
{
	fstream fin("nim.in", ios::in);
	fstream fout("nim.out", ios::out);
	
	int n;	
	
	fin >> n;
	for (int i = 0, m; i < n; ++i) {
		int x = 0;
		fin >> m;
		for (int j = 0, y; j < m; ++j) {
			fin >> y;
			x ^= y;
		}
		
		fout << (x ? "DA" : "NU") << "\n";
	}	
	
	fin.close();
	fout.close();
	return 0;
}
