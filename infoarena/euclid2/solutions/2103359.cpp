#include <fstream>

using namespace std;

int cmmdc(int a, int b){
	if (b == 0)
		return a;
	return cmmdc(b, a % b);
}

int main(){
	ifstream fIn("euclid2.in");
	ofstream fOut("euclid2.out");
	int T, a, b;
	fIn >> T;
	for (int i = 1; i <= T; i++){
		fIn >> a >> b;
		fOut << cmmdc(a, b) << '\n';
	}
	fIn.close();
	fOut.close();
	return 0;
}
