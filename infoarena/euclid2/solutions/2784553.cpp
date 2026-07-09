#include <fstream>
#include <iostream>
using namespace std;


int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	long long  perechi, a , b;
	in >> perechi;
	for (int e = 0; e < perechi; e++){
		a = 0; b = 0;
		in >> a >> b;
		while(a !=b){
			if(a >b)
				a-=b;
			else 
				b-=a;
	}
		out << a<< '\n';
	}}
