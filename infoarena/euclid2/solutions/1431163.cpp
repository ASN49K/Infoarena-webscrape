#include <iostream>
#include <fstream>

#define INPUT_FILE "euclid2.in"
#define OUTPUT_FILE "euclid2.out"

using namespace std;

// Algoritmul lui Euclid prin impartiri
int euclid(int a, int b) {
	int r = -1;
	while (r != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	fstream in, out;
	int numberOf, a, b;

	in.open(INPUT_FILE, fstream::in);
	out.open(OUTPUT_FILE, fstream::out);

	in >> numberOf;
	for (int i = 0; i < numberOf; i++) {
		in >> a >> b;
		out << euclid(a, b) << endl;
	}

	in.close();
	out.close();
	return 0;
}