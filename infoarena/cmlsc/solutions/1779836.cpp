#include <iostream>
#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int vect[300][300],nr1,nr2;
int result[1000],contor=-1;
void form(){
	int aux;
	f>>nr1>>nr2;
	nr1 += 2;
	nr2 += 2;
	for(int i=2;i<nr1;++i){
		f>>aux;
		vect[0][i] = aux;
	}
	for(int i=2;i<nr2;++i){
		f>>aux;
		vect[i][0] = aux;
	}
}
int max(int a,int b){
	return (a>b) ? a : b;
}
void afisare(){
	for(int i=0;i<nr2;++i){
		for(int j=0;j<nr1;++j)
			cout << vect[i][j] << " " ;
		cout << "\n";
	}
}
void lms(){
	for(int i=2;i<nr2;++i){
		for(int j=2;j<nr1;++j){
			if((vect[i][0]==vect[0][j]) && (vect[i][j] + 1<=i))
				vect[i][j] += vect[i-1][j-1] + 1;
			else
				vect[i][j] = max(vect[i-1][j],vect[i][j-1]);
		}
	}
}
void rez(){
	for(int i=nr2-1;i>=2;--i){
		for(int j=nr1-1;j>=2;--j){
			if(vect[i][0] == vect[0][j]){
				result[++contor] = vect[i][0];			
				--i;
			}
			else
				if(vect[i-1][j]<vect[i][j-1]){
					++j;
					--i;
				}
		}
	}
}

void afis(){
	g << contor+1 << "\n";
	for(int i=contor;i>=0;--i)
		g << result[i] << " ";
	g << "\n";
}

int main(){
	form();
	lms();
	afisare();
	rez();
	afis();
	return (0);
}
