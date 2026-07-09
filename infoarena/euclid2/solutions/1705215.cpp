#include<iostream>
#include<fstream>

int euclid(int a, int b){
	if (b==0)
		return a;
	else
		return euclid(b, a%b); 
}

int main(){
	std::ifstream input;
	std::ofstream output;
	input.open("euclid2.in");
	output.open("euclid2.out");

	int nr;
	input >> nr;
	int a,b;
	for (int i=0;i<nr;i++){
		input>>a>>b;
		int rest=euclid(a,b);
		output<<rest;
		output<<"\n";
	} 

	input.close();
	output.close();
	return 0;
}