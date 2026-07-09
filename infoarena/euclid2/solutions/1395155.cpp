#include <iostream>
#include <fstream>
#include<time.h>
using namespace std;

int cmmmdc(int a, int b){
	if (a == b)
		return a;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if ((~a & 1) && (b & 1))
		return cmmmdc(a >> 1, b);
	else if ((~a & 1) && (~b & 1))
		return cmmmdc(a >> 1, b >> 1) << 1;
	else if ((a & 1) && (~b & 1))
		return cmmmdc(a, b >> 1);
	else
		if (a > b)
			return cmmmdc((a - b) >> 1, b);
	return cmmmdc((b - a) >> 1, a);
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