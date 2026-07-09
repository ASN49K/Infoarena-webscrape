#include<iostream>
#include<fstream>
using namespace std;

int euclid(int a, int b){
	if (b == 0){
		return a;
	}
	else{
		return euclid(b, a%b);
	}
}

int main(){
	ifstream f("euclid2.in");
	ofstream o("euclid.out");
	int n = 0; f >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		f >> a >> b;
		o << euclid(a, b) << endl;
	}
	return 0;
}