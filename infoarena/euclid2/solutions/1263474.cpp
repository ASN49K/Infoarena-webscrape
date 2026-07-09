#include<iostream>
#include<fstream>

using namespace std;

int divizor(int a, int b);
inline int bigger(int a, int b);
inline int smallest(int a, int b);

int main(){
	int perechi,a,b;
	ifstream input("euclid2.in");
	ofstream output("euclid2.out");
	input >> perechi;
	for (int i = 1; i <= perechi; i++){
		input >> a >> b;
		output << divizor(a,b) << endl;
	}
	input.close();
	output.close();
	return 0;
}

int divizor(int a, int b){
		while(true){
			if ((bigger(a,b)%smallest(a,b)) == 0){
				return smallest(a,b);
			}
			else{
				if (bigger(a, b) == a){
					a -= b;
				}
				else{
					b -= a;
				};
			}
		}

}

inline int bigger(int a, int b){
	if (a > b){ return a; }
	else{ return b; }
}

inline int smallest(int a, int b){
	if (a > b){ return b; }
	else{ return a; }
}