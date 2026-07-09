#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main(){
	int a, b, n;
	fin >> n;
	while (n) {
		n--;
		fin >> a >> b;
		while (a > 1 && b > 1) {
			if (a > b) {
				a -= b;
			}
			else if (b > a) b -= a;
			else break;
		}
		if (a > b) fout << b<<'\n';
		else fout << a<<'\n';
	}
}