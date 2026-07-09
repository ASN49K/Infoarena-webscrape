#include<fstream>
using namespace std;

int cmmdc(int x, int y){
	if(x == 0) return y;
		else if(y == 0) return x;
			else return cmmdc(y, x%y); 
}

int main(){

	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int x, y, cm, aux, n, i;
	fin >> n;
	for(i=0; i<n; i++){
		fin >> x >> y;
		if(x < y){
			aux = x;
			x = y;
			y = aux;
		}
		cm = cmmdc(x, y);
		fout << cm << "\n";
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
