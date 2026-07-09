// http://infoarena.ro/problema/euclid2
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

inline int cmmdc(int first,int second) {
	if(!second)
		return first;
	else
		return cmmdc(second,first % second);
}

int main() {
	int total,first,second;

	in >> total;
	for(int i=1;i<=total;i++) {
		in >> first >> second;

		out << cmmdc(first,second) << "\n";
	}

	in.close();
	out.close();

	return (0);
}
