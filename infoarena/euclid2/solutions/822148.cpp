#include <fstream>
using namespace std;





int main() {
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	register int n;
    fin >> n;

	
    for (; n > 0; --n) {
		register int a, b, r;
		fin >> a >> b;
		do
		{
			r = a % b;
			a = b;
			b = r;
		}
		while( r );
        fout << a << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
