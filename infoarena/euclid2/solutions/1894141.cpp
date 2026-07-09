#include <fstream>

int euclid(int a, int b) {

	int c;

	while (b) {
		c = a;
		a = b;
		b = c % b;
	}

	return a;

}


int main() {

	int a, b, nr;

	std::ifstream in;
	std::ofstream out;

	in.open("euclid2.in");
	out.open("euclid2.out");

	in >> nr;

	while (nr--) {

		in >> a >> b;
		out << euclid(a, b) << std::endl;
	
	}

	return 0;
}