#include <fstream> //biblioteca pentru lucru cu fisiere

using namespace std; // nu mai scriu std:: de fiecare data

ifstream fin("euclid2.in"); //declar fisierul 1
ofstream fout("euclid2.out"); //declar fisierul 2

int main(){ // functia de baza
	int a, b, c, T; // declar variabile
	fin>>T; // din .in luam numarul de perechi care vrem sa le introducem
	for(int i = 1; i<=T; i++){ //un for pentru a face atatea perechi de numere
		fin>>a>>b; //luam a si b, adica cele 2 numere in for
		while(b!=0){
			c=a%b;
			a=b;
			b=c;
		}
		fout<<a<<'\n';
	}
}
