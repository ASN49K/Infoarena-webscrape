#include <fstream>
using namespace std;
int processPair(long a, long b) {
	int r = a % b;
	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main(int argc, char** argv) {
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	int numberOfEntries;
	f >> numberOfEntries;
	while (numberOfEntries > 0) {
		int a,b;
		f >> a;
		f >> b;
		g << processPair(a, b) << endl;
		numberOfEntries --;
	}
	return 0;
}
