#include <iostream>
#include <fstream>

using namespace std;
	
int cmmdc(int num1, int num2){
	
	while(num1 != num2){
		if(num1 > num2){
			num1 -= num2;
		}
		else{
			num2 -= num1;
		}
	}
	
	return num2;
}	

int main(){

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int pairs = 0, number1, number2;
	
	while(pairs == 0 ){
		fin>>pairs;
		if(pairs >= 100000){
			pairs = 0;
		}
		if(pairs < 1){
			pairs = 0;
		}
	}	
	for(int i = 0; i < pairs; i++){
			fin>>number1;fin>>number2;
			fout<<cmmdc(number1, number2)<<endl;
	}

fin.close();
fout.close();
return 0;
}
 
