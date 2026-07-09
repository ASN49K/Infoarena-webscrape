/*Cel mai mare divizor comun dintre doua numere naturale a si b este cel mai mare numar natural pozitiv d care divide ambele numere.*/
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b) {
	if (!b) return a;
	return euclid(b, a%b);
}

int main() {
	int t, a, b;
	in >> t;
	while (t--) {
		in >> a >> b;
		out << euclid(a, b) << endl;
	}
	return 0;
}