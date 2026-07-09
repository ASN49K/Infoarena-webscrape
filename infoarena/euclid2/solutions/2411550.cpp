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
		
	for(int i=1; i<=T; i++){
		
		fin >> a >> b;
		
		if(a % b == 0){
			cmmdc = b;
		}
		else if(b % a == 0){
			cmmdc = a;
		}
		else if(a < b){
			for(int j=a; j>=2; j--){
				if(a % j == 0 && b % j == 0){
					cmmdc = j;
					break;	
				}
			}
		}
		else if(a > b){
			for(int j=b; j>=2; j--){
				if(a % j == 0 && b % j == 0){
					cmmdc = j;
					break;
				}
			}
		}
		
		fout << cmmdc << endl;
	
	}

	

	
	return 0;
}
