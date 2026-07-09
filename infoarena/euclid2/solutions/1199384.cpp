#include<iostream>
#include<fstream>

using namespace std;

int main(){

	long long T;
	long long a, b, r;
	ifstream f("euclid2.in", ios::in);
	ofstream g("euclid2.out", ios::out);

	f >> T;
	for (int i = 0; i<T; ++i){
		f >> a >> b;
		while (b != 0){
			r = a%b;
			a = b;
			b = r;
			
		}
		g << a << '\n';
	}

	f.close();
	g.close();

	return 0;
}
