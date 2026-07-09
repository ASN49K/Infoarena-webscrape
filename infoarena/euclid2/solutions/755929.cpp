#include <fstream>

using namespace std;

int a,b,s;

int cmmdc(int a, int b) {
	 if(!b) return a;
	 return cmmdc(b, a%b);
}

int main(){
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>s;

	for(s;s;--s){
		f>>a>>b;
		g<<cmmdc(a,b)<<endl;
	}

	return 0;

}
