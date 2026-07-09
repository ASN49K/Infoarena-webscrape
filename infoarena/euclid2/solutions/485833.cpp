#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,b,a,nr1,nr2;
int divizor(int a,int b){
	int aux;
	while(b){
		aux=b;
		b=a%b;
		a=aux;
	}
	return a;
}
int main(){
	f>>n;
	f>>nr1>>nr2;
	do{
	    if(nr1>nr2) g<<divizor(nr1,nr2)<<"\n";
		else g<<divizor(nr2,nr1)<<"\n";
		f>>nr1>>nr2;
	}while(!f.eof());
	g.close();
	return 0;
}

		