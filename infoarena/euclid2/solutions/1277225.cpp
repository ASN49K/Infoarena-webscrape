#include <fstream>
#include <iostream>
using namespace std;

int euclid(int a, int b){
	if (!b)
		return a;
	euclid(b, a%b);
}

int main(void)
{
	int T, a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f >> T;
	while (T>0){
		f >> a >> b;
		g << euclid(a, b) << '\n';
		T--;
	}
	f.close();
	g.close();

	return 0;
}

