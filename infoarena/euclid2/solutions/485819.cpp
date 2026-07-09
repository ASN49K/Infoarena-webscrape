#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,b,a,i;
int divizor(int a,int b){
	int aux;
	while(b){
		aux=b;
		b=a%b;
		a=b;
	}
	return a;
}
int main(){
	f>>n;
	while(f.eof()){
		f>>a>>b;
	    g<<divizor(a,b)<<"\n";
	}
	g.close();
	return 0;
}

		