#include <fstream>

using namespace std;

int cmmdc(int a, int b){
	int r;
	while (a % b != 0){
		r = a % b;
		a = b;
		b = r;
	}
	return b;
}

int main(){
	ifstream fIn("euclid2.in");
	ofstream fOut("euclid2.out");
	int T, a, b;
	fIn >> T;
	for (short i = 1; i <= T; i++){
		fIn >> a >> b;
		fOut << cmmdc(a, b) << '\n';
	}
	return 0;
	fIn.close();
	fOut.close();
}
