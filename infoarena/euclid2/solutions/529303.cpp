// http://infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main() {
	int total,first,second;

	in >> total;
	for(int i=1;i<=total;i++) {
		in >> first >> second;

		while(first != second)
			if(first > second)
				first = first - second;
			else
				second = second - first;

		out << first << "\n";
	}

	in.close();
	out.close();

	return (0);
}
