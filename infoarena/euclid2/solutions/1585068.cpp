#include <fstream>
#include <vector>

using namespace std;

int euclid(int a, int b) {
    if (b == 0) {
	return a;
    } else {
	return euclid(b, a % b);
    }
}

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
	int a, b;
	fin >> a >> b;
	fout << euclid(a, b) << endl;
    }

    return 0;
}
