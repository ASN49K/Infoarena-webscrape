#include <fstream>

using namespace std;

int main(){
	int T, a, b, r;
	
	ifstream fIn("euclid2.in");
	ofstream fOut("euclid2.out");
	
	fIn >> T;
	
	for (short i = 1; i <= T; ++i){
		fIn >> a >> b;
		
		if (a == 0)
			fOut << b << endl;
		else{
			while(b != 0) {
				r = a % b;
				a = b;
				b = r; 
			}
			fOut << a << endl;
		}
	}
	
	fIn.close();
	fOut.close();
	return 0;
}
