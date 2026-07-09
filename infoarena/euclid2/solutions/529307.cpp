// http://infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
	int total,first,second,aux;

	in >> total;
	for(int i=1;i<=total;i++) {
		in >> first >> second;

		while(second) {
			aux = second;
			second = second % first;
			first = aux;
		}

		out << first << "\n";
	}

	in.close();
	out.close();

	return (0);
}
