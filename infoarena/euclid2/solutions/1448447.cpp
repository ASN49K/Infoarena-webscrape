#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

long cmmdc(long a, long b){
	if (!b) return a;
	else cmmdc(b, a%b);
}

int main(){

	//double sum = 0;
	//clock_t start_s = clock();

	ifstream ifile("euclid2.in");
	ofstream ofile("euclid2.out");
	long T, a, b;
	ifile >> T;

	while (T != 0){
		T--;
		ifile >> a >> b;
		ofile << cmmdc(a, b) << endl;
	}

	return 0;


	//int x = 0;

	//clock_t stop_s = clock();
	//sum = ((double)(stop_s - start_s) / CLOCKS_PER_SEC) / 100000; //average time

	//cout << sum << endl;

	//system("pause");
}
