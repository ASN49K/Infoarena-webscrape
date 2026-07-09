#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int n, a, b, i, r;

	ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
	
	for(i=1; i<=n; i++){
		{
		 fin >> a;
		 fin >> b;
	    }
	{while (b!=0){
			r = a %b;
			a = b;
			b =r;
			}
		fout << a;
	}
	return 0;
	}
}



