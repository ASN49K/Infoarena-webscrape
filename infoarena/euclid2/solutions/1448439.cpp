#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

int cmmdc(int a, int b){
	if (!b) return a;
	else cmmdc(b, a%b);
}

int main(){

	//double sum = 0;
	//clock_t start_s = clock();

	ifstream ifile("euclid2.in");
	ofstream ofile("euclid2.out");
	double T, a, b;
	ifile >> T;

	for (double i = 0; i < T; i++){
		ifile >> a >> b;
		ofile << cmmdc(a, b) << endl;
	}


	//int x = 0;

	//clock_t stop_s = clock();
	//sum = ((double)(stop_s - start_s) / CLOCKS_PER_SEC) / 100000; //average time

	//cout << sum << endl;

	//system("pause");
}
