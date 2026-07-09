#include <iostream>
#include <cstdio>
using namespace std;

int cmmdc(int a, int b){
	int r = a % b;
	while(r != 0){
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}


int main(void){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	int a;
	int b;
	int nrOfTrials;
	cin >> nrOfTrials;

	for(int i=0; i<nrOfTrials; i++){
		cin >> a >> b;
		cout << cmmdc(a,b);
	}

	return 0;
}