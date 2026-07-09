#include<iostream>
#include<fstream>
using namespace std;

int main(){
	
	int T;
	int a, b;
	int cmmdc = 0;
	
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	fin >> T;
	
	if(T >=1 && T <= 100000){
	
	for(int i=1; i<=T; i++){
		fin >> a >> b;
		if(a == b){
			cmmdc = a;
		}
		else if(a < b){
			for(int j=a; j>=1; j--){
				if(a % j == 0 && b % j == 0){
					cmmdc = j;
					break;	
				}
			}
		}
		else{
			for(int j=b; j>=1; j--){
				if(a % j == 0 && b % j == 0){
					cmmdc = j;
					break;
				}
			}
		}
		
		fout << cmmdc << endl;
		
	}
	
}
	
	return 0;
}
