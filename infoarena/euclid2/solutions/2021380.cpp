#include<fstream>
using namespace std;

int cmmdc(int b, int a)
{
	if (b == 0) return a;
	else return(b, a%b);
}

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
		g << cmmdc(a, b) << endl;
	}
	return 0;
}