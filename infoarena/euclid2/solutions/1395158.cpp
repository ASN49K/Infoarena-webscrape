#include <iostream>
#include <fstream>
using namespace std;

int cmmmdc(int a, int b){
	if (a == b)
		return a;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a % 2 == 0 && b %2 == 1)
		return cmmmdc(a / 2, b);
	else if (a % 2 == 0 && b %2 == 0)
		return cmmmdc(a / 2, b / 2) * 2;
	else if (a % 2 == 1 && b %2 == 0)
		return cmmmdc(a, b / 2);
	else
		if (a > b)
			return cmmmdc((a - b) / 2, b);
	return cmmmdc((b - a) / 2, a);
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
		f_out << res << '\n';
		i++;
	}

	f_in.close();
	f_out.close();
	return 0;
}