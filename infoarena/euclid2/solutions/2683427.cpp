#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t,a ,b,temp;

int main() {
	in >> t;

	while (t) {

		in >> a >> b;
		cout << a <<" "<< b << '\n';

		while ((temp = a % b) != 0) {
			a = b;
			b = temp;
		}

		out << b << " ";


		--t;
	}

	in.close();
	out.close();
	return 0;
}