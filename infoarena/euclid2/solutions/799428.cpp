#include<fstream>
using namespace std;

int cmmdc(int x, int y){
	if(x == 0) return y;
		else if(y == 0) return x;
			else return cmmdc(y, x%y); 
}

int main(){

	ifstream fin("cmmmdc.in");
	ofstream fout("cmmmdc.out");
	
	int x, y, cm, aux;
	fin >> x >> y;
	if(x < y){
		aux = x;
		x = y;
		y = aux;
	}
	cm = cmmdc(x, y);
	fout << cm;
	
	fin.close();
	fout.close();
	
	return 0;
}
