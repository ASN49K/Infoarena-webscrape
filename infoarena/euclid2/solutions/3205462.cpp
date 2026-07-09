#include <iostream>
#include <fstream>
using namespace std;

string file="euclid2";

ifstream fin(file + ".in");
ofstream fout(file + ".out");



int main(){

	int n;
	cin >> n;

	int a;
	int b;

	int c=1;
	while (n--){
		fin >> a;
		fin >> b;

		while(b){
			c=a%b;
			a=b;
			b=c;
		}
		fout << a;
	}



	return 0;
}