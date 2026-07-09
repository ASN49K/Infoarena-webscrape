
#include<fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream out("euclid2.out");


int gcd(int a, int b) {

	if (!b) return a;
	return gcd(b, a % b);

}



int main() {


	int n, x, y;

	fin >> n;
	for (;n;n--){
		fin >> x >> y;
		out << gcd(x, y)<<endl;
	}

	return 0;
}




