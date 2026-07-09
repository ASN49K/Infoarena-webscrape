#include <fstream>

using namespace std;
unsigned int o,ymax, y[1024],x[1024],A[1024],B[1024],n,N,M,j, k,l ;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void afiseaza() {
	out<<ymax<<"\n";
	for(unsigned int i=0; i<ymax; i++) out<<y[i]<<" ";
}

void inregistrare(unsigned int l) {
	if(o==0) {	ymax=l;	for(unsigned int i=0; i<ymax; i++) y[i]=x[i]; o=1; }
	if(ymax<l) { ymax=l; for(unsigned int i=0; i<ymax; i++) y[i]=x[i]; }
}

unsigned int potrivire(unsigned int tz) {
	for(unsigned int i=n; i<N; i++) 
		if(B[i]==tz) {
			n=i;
			return 1;
		}	
	return 0;	
}

void sir() {
	k=0; j=0; l=0;
	while(k<M) {
		x[l]=A[j];
		if(j==M) { inregistrare(l); n=0; k++; j=k; l=0; }
		else if(potrivire(A[j])) {
			j++; l++; 
		} else j++;
	}	
}

void citire(unsigned int &P, unsigned int X[1024]) {
	for(unsigned int i=0; i<P; i++) in>>X[i];
}
int main() {
	o=0;
	in>>M>>N;
	citire(M,A);
	citire(N,B);
	sir();
	afiseaza();
	return 0;
}
