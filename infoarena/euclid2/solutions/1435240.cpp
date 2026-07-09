#include <iostream>
#include <fstream>

#define INPUT_FILE "euclid2.in"
#define OUTPUT_FILE "euclid2.out"

std::fstream in(INPUT_FILE, std::fstream::in);
std::fstream out(OUTPUT_FILE, std::fstream::out);

using namespace std;

int euclid(int a, int b) {
	int r = -1;
	while(r != 0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int aux1, aux2;
	int numberOf = 0;
	in >> numberOf;
	for (int i = 0; i < numberOf; i++) {
		in >> aux1 >> aux2;
		out << euclid(aux1, aux2) << "\n";
	}

	out.close();
	in.close();
	return 0;
}
