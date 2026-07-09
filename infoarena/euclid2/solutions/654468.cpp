#include <iostream>
#include <cstdio>
using namespace std;

long int cmmdc(long int a, long int b){
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
	
	long int a;
	long int b;
	int nrOfTrials;
	scanf("%d", &nrOfTrials);

	for(int i=0; i<nrOfTrials; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", cmmdc(a,b));
	}

	return 0;
}