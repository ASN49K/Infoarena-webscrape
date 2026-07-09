#include <iostream>
#include <fstream>
using namespace std;

int cmmmdc(int a, int b){
	if (a == b)
		return a;
	if (a > b)
		cmmmdc(a - b, b);
	else
		cmmmdc(a, b - a);
}

int main()
{
	ifstream f_in("euclid2.in");
	ofstream f_out("euclid2.out");
	int n, i = 0, a, b, res;
	f_in >> n;
	while (i < n){
		f_in >> a;
		f_in >> b;
		res = cmmmdc(a, b); 
		f_out << res << endl;
		i++;
	}

	f_in.close();
	f_out.close();
	return 0;
}