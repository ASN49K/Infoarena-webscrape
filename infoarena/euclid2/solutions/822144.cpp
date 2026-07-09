#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");



int main() {
	register int n, a, b, r;
    fin >> n;

	
    for (; n > 0; n--) {
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
