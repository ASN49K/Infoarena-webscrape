#include <fstream>
using namespace std;
unsigned int M,N, A[1024], B[1024],n,j,x[1024];
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void afiseaza(unsigned int j) {
	out<<j<<"\n";
	for(unsigned int i=0; i<j; i++) out<<x[i]<<" ";
}

int match(unsigned int tz) {
	for(unsigned int i=n; i<=N; i++) 
		if(B[i]==tz) {
			n=i;
			return 1;
		}			
	return 0;
}

unsigned int sir(unsigned int k, unsigned int j) {
	if(k==M) { afiseaza(j); return 0; }
	else while(k<M) {
		x[j]=A[k];
		if(match(A[k])) { if(!sir(k+1,j+1)) return 0; }
		else k++;
	}
	return 0;
}
void citire(unsigned int &P, unsigned int X[1024]) {
	for(unsigned int i=0; i<P; i++) in>>X[i];
}
int main() {
	n=0;
	in>>M>>N;
	citire(M,A);
	citire(N,B);
	sir(0,0);
	return 0;
}
