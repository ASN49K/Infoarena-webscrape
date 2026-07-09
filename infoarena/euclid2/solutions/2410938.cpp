#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	int T;
	int a, b;
	int cmmdc;
	
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	fin >> T;
	
	for(int i=1; i<=T; i++){
		fin >> a >> b;
		if(a == b){
			cmmdc = a;
		}
		else if(a < b){
			for(int j=1; j<=a; j++){
				if(a % j == 0 && b % j == 0){
					cmmdc = j;	
				}
			}
		}
		else{
			for(int j=1; j<=b; j++){
				if(a % j == 0 && b % j == 0){
					cmmdc = j;
				}
			}
		}
		
		fout << cmmdc << endl;
		
	}
	
	
	
	return 0;
}
