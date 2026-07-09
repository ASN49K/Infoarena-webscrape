#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream in;
	in.open("euclid2.in");
	ofstream out;
	out.open("euclid2.out");
	
	if(!in){
		cout << "not open!";
		return 0;
	}
	
	int t;
	in >> t;
	while(t--){
		int a, b;
		in >> a >> b;
		int r = a % b;
		while(r){
			a = b;
			r = a % b;
			b = r;
		}
		cout << a << "\n";
	}	
	return 0;
}
