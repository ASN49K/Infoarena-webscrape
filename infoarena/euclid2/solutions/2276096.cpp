#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

int n;
int x, y;
int r;

int main(){
	fin >> n;
	while(n--){
		fin >> x >> y;
		while(y){
			r = x % y;
			x = y;
			y = r;
		}
		fout << x << endl;
	}
}
