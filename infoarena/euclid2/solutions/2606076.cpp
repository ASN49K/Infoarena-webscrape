#include <iostream>

using namespace std;

// declaram variabilele
int a, b, p, x;
// scriem functia recursiva cmmdc
int cmmdc(int a, int b){	
	if (a%b == 0){
		return b;
	}else {
		return cmmdc(b, a%b);
	}
}

int main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	// citim nr de perechi
	cin >> p;
	for(int i = 1; i <= p; i++){
	// citim de la tastatura cele 2 numere
	cin >> a >> b;
	x  =  cmmdc(a, b);	
	cout << x << '\n';
	}	
	return 0;
}
