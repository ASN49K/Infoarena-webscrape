#include<iostream>
#include<fstream>
using namespace std;

ofstream fisOut("euclid2.out");
ifstream fisIn("euclid2.in");

int matrice[10][10], nrLinii;
void afisare(){
//	cout << "Da numarul de linii: ";
	fisIn >> nrLinii;
	//cout << nrLinii;
	for (int i = 0; i <nrLinii; i++){
		for (int j = 0; j < 2; j++){
		//	cout << "Da elementul" << "[" << i << "]" << "[" << j << "]" << ": ";
			fisIn >> matrice[i][j];
		}
	}
	int retine;
	for (int i = 0; i < nrLinii; i++){
		//cout << endl;
		for (int j = 0; j < 2; j++){
			if (matrice[i][j] <  matrice[i][j + 1]){
				retine = matrice[i][j];
			}
			else{
				retine = matrice[i][j + 1];
			}
			for (int p = retine; p >= 1; p--){
				if (matrice[i][j] % p == 0 && matrice[i][j + 1] % p == 0){

			
						fisOut << p << endl;
				
					break;
				}
			}
		}
	}


}

int main(){

	afisare();


	return 0;
}