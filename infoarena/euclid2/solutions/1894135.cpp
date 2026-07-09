#include <fstream>

int euclid(int a, int b) {

	if (!b) return a;
	return euclid(b, a % b);

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
		out << euclid(a, b);
	
	}

	return 0;
}