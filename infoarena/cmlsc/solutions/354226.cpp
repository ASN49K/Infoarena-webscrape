#include <fstream>
using namespace std;
unsigned int M,N, A[1024], B[1024],n,j,x[1024];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int match(unsigned int tz) {
	for(unsigned int i=n; i<=N; i++) 
		if(B[i]==tz) {
			n=i;
			return 1;
		}			
	return 0;
}

void sir(unsigned int k, unsigned int j) {
	if(k==M) afiseaza();
	else while(k<M) {
		x[j]=A[k];
		if(match(A[k])) sir(k+1,j+1);
		else k++;
	}
	
}
void citire(unsigned int &P, unsigned int X[1024]) {
	in>>P;
	for(unsigned int i=0; i<=1024; i++) in>>X[i];
}
int main() {
	n=0;
	citire(M,A);
	citire(N,B);
	sir(0,0);
	return 0;
}
