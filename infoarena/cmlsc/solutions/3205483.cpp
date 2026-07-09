#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string file="cmlsc";

ifstream fin(file + ".in");
ofstream fout(file + ".out");

int vec1[1025];
int vec2[1025];
int vecConstructie[1025];

bool notat1[1025];
bool notat2[1025];
int munteConstructie[1025];

int main(){

	int a, b;
	fin >> a >> b;

	for(int i=1;i<=a;i++){
		fin >> vec1[i];
	}
	for(int i=1;i<=b;i++){
		fin >> vec2[i];
	}
	

	int contorConstructie=0;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(vec1[i]==vec2[j] && notat2[j]==0){
				vecConstructie[++contorConstructie]=vec1[i];
				notat2[j]=1;
				break;
			}
		}
	}
	int nContor=contorConstructie;

	// for(int i=1;i<=nContor;i++)
	// 	fout << vecConstructie[i] << ' ';
	// fout << '\n';






	int celMaiMareCurent=0;
	munteConstructie[0]=1;
	munteConstructie[1]=1;
	for(int i=1;i<=nContor;i++){
		
		for(int j=i-1;j>=1;j--){
			if(vecConstructie[i]>vecConstructie[j]) // ATENTIE AICI, NU STIU DACA E STRICT CRESCATOR SAU DOAR CRESCATOR
				if(munteConstructie[j]>celMaiMareCurent)
					celMaiMareCurent = munteConstructie[j];
			
		}
		celMaiMareCurent++;
		munteConstructie[i]=celMaiMareCurent;
		celMaiMareCurent=0;
	}

	// for(int i=1;i<=nContor;i++)
	// 	cerr << vecConstructie[i] << ' ';
	// cerr << '\n';

	// for(int i=1;i<=nContor;i++)
	// 	cerr << munteConstructie[i] << ' ';
	// cerr << '\n';



	int biggestYet=0;
	for(int i=nContor;i>=1;i--){	
		biggestYet=max(biggestYet, munteConstructie[i]);
	}

	fout << biggestYet<< '\n';

	vector<int> final;
	for(int i=nContor;i>=1;i--){
		if(biggestYet==munteConstructie[i]){
			biggestYet--;
			final.push_back(vecConstructie[i]);
		}
	}


	for(vector<int>::reverse_iterator it = final.rbegin(); it!=final.rend() ; it++)
		fout << *it << ' ';


	return 0;
}