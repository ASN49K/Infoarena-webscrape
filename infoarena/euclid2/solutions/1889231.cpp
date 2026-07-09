#include <iostream>
#include <fstream>

int cmmdc(int a, int b) {
	if (!b) return a;
	
	return cmmdc(b, a%b);
}

int main(void) {

	std::ifstream in("euclid2.in");
	std::ofstream out("euclid2.out");

	int n;
	in >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		in >> a >> b;
		out << cmmdc(a, b) << std::endl;
	}

	in.close();
	out.close();

	return 0;
}

