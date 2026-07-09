#include <cstdio>
using namespace std;
 int a,b, T, i, r;
int main() {
	FILE *in, *out;
in=fopen("euclid2.in", "rt");
out=fopen("euclid2.out", "w+");

 fscanf (in, "%d", &T);
 if ((T>=1)&&(T<=100000)){
 
 for (i=1; i<=T; i++) {
fscanf (in, "%d", &a);
fscanf (in, "%d", &b);
 	while(b!=0){
		r=a%b;
		a=b;
		b=r;}
 	fprintf (out, "%d\n", a);
}
}

 return 0;
}
