#include <iostream>
#include <fstream>

using namespace std;

int gcd (int a , int b) {
	if (b != 0) {
		a = a % b;
		return gcd(b, a);
	}
	return a;
}
  
int main() 
{
	ifstream in_file;
	ofstream out_file;
	int n = 0, i = 0, a = 0, b = 0;
	
	in_file.open("euclid2.in");
	out_file.open("euclid2.out", ios::trunc);

	if ( in_file.is_open() ) {
		in_file>>n;
		for (i = 0; i < n ; i ++) {
			in_file>>a;
			in_file>>b;
			out_file<<gcd(a, b)<<endl;
		}
	} else {
		return -1;
	}
	
	if (out_file.is_open()) {
		in_file.close();
		out_file.close();
		return 0;
	} else {
		in_file.close();
		return -1;
	}
}
