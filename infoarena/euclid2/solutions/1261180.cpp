#include <iostream>
#include <fstream>

using namespace std;

int gcd (int a , int b) {
	if (b != 0) {
		return gcd(b, a % b);
	}
	return a;
}
  
int main() 
{
	ifstream in_file;
	ofstream out_file;
	int n = 0, i = 0, a = 0, b = 0;
	
	in_file.open("euclid2.in");
	out_file.open("euclid2.out");

	in_file>>n;
	for (i = 0; i < n ; i ++) {
		in_file>>a;
		in_file>>b;
		out_file<<gcd(a, b)<<endl;
	}

	in_file.close();
	out_file.close();
	return 0;
}
