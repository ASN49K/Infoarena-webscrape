#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t, a, b;
int cmmdc (int A, int B){
    if (B==0) return A;
    else return cmmdc(B, A%B);
}
int main (){
	f>>t;
	while (t--){
        f>>a>>b;
        g<<cmmdc(a, b)<<'\n';
	}
	return 0;
}
