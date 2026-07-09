#include <fstream>
using namespace std;
unsigned int M,N, A[1024], B[1024],n,j,x[1024],y[1024],ymax,o=0;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void afiseaza() {
	out<<ymax<<"\n";
	for(unsigned int i=0; i<ymax; i++) out<<y[i]<<" ";
}
void inregistreaza(unsigned int j) {
	if(o==0) {	ymax=j;	for(unsigned int i=0; i<ymax; i++) y[i]=x[i]; o=1; }
	if(ymax<j) { ymax=j; for(unsigned int i=0; i<ymax; i++) y[i]=x[i]; }
}

int match(unsigned int tz) {
	for(unsigned int i=n; i<N; i++) 
		if(B[i]==tz) {
			n=i;
			return 1;
		}			
	return 0;
}

void sir(unsigned int k, unsigned int j,unsigned int init) {
	if(init==M) { afiseaza(); exit(0); }
	if(k==M) { inregistreaza(j); sir(init+1,0,init+1); }
	else while(k<M) {
		x[j]=A[k];
		if(match(A[k])) sir(k+1,j+1, init);
		else sir(k+1,j,init);
	}
}
void citire(unsigned int &P, unsigned int X[1024]) {
	for(unsigned int i=0; i<P; i++) in>>X[i];
}
int main() {
	n=0;
	in>>M>>N;
	citire(M,A);
	citire(N,B);
	sir(0,0,0);
	return 0;
}
