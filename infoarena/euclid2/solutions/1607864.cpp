#include <iostream>
#include <fstream>

long int euclid(long int a, long int b) {

	while(a && b){
		if(a > b){
			a = a%b;
		}
		else if(a < b){
			b = b%a;
		}
		else{
			return a;
		}
	}

	return (!a) ? b : a; 
}

int main(){

	long int a, b, d, n;
	int i = 0;

	std::ifstream input ("euclid2.in");
	std::ofstream output ("euclid2.out");
	if(input.is_open()){
		input >> n;
		for(int i=0;i<n;i++){
			input >> a;
			input >> b;
			d = euclid(a,b);
			output << d << std::endl;
		}		
	}

	return 0;
}