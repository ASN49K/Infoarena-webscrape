#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

unsigned int euclid(unsigned int a, unsigned int b) {
	while (b) {
		unsigned int aux = a;
		a = b;
		b = aux % b;
	}
	return a;
}

int main() {
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	unsigned int T;
	in >> T;

	for (unsigned int index = 0; index < T; index++) {
		unsigned int a, b;
		in >> a >> b;
		out << euclid(max(a, b), min(a, b)) << '\n';
	}

	in.close();
	out.close();

	return 0;
}