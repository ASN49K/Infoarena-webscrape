#include<fstream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream in;
	ofstream out;
	in.open("euclid.in");
	out.open("euclid.out");
	int n;
	in >> n;
	for(int i=0;i<n;++i) {
		int a, b;
		in >> a >> b;
		while(b != 0) {
			int r = a % b;
			a = b;
			b = r;
		}
		out << a << "\n";
	}
	out.close();
	in.close();
	return 0;
}

