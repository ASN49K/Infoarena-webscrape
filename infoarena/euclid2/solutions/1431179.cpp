#include <iostream>
#include <fstream>

#define INPUT_FILE "euclid2.in"
#define OUTPUT_FILE "euclid2.out"

using namespace std;

std::ifstream in(INPUT_FILE);
std::ofstream out(OUTPUT_FILE);

// Algoritmul lui Euclid prin impartiri
int euclid(int a, int b) {
	int tmp;
	if (a == 0) {
		return b;
	}
	while (b != 0) {
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	int numberOf, a, b;

	in >> numberOf;
	for (int i = 0; i < numberOf; i++) {
		in >> a;
		in >> b;
		out << euclid(a, b) << "\n";
	}

	in.close();
	out.close();
	return 0;
}