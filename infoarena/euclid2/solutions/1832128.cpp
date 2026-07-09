#include<fstream>
using namespace std;

int main()
{
	int a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T;
	int r;
	f >> T;
	for (int i = 0; i < T; i++){
		f >> a >> b;
		while (b != 0)
		{
			r = a%b;
			a = b;
			b = r;
		}
		g << a << endl;
	}
	return 0;
}