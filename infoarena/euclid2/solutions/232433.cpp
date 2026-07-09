#include<fstream.h>

long euclid(long a, long b) {
	if(b==0)
		return a;
	else
		euclid(b, a%b); }

int main(void) 				{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	long a, b, t;

	f>>t;
	for(long i=0; i<t; i++) {
		f>>a>>b;
		g<<euclid(a,b)<<'\n'; } 	}