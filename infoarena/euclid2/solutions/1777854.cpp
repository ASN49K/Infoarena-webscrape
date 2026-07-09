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

int pairs, number1, number2;
	
	fin>>pairs;
	for(int i = 0; i < pairs; i++){
			fin>>number1;fin>>number2;
			fout<<cmmdc(number1, number2)<<endl;
	}

fin.close();
fout.close();
return 0;
}
 
