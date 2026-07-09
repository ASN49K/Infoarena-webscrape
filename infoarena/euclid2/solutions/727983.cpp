#include <fstream>
using namespace std;

void cmmdc(int &a,int  &b){
	int aux;
	while(b){
		aux=a%b;
		a=b;
		b=aux;}}

int main(){
	int a,b;
	ifstream f("cmmdc.in");
	ofstream g("cmmdc.out");
	f>>a>>b;
	cmmdc(a,b);
	g<<a;
	f.close();
	g.close();
	return 0;}

