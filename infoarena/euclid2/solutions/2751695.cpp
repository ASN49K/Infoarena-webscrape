#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a, int b) {
	/*if (!b)
		return a;
	else
		return euclid(b, a % b);
		*/
	int r;
    r=a%b;
    while(r>0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main() {
	int T;
	int a, b;
	fin >> T;
	for (int i = 1; i <= T; ++i) {
		fin >> a >> b;
		fout << euclid(a, b) << endl;
	}
	return 0;
}