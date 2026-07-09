#include <iostream>
#include <fstream>

int lnko(int a, int b){
	while(b != 0){
		int temp = a;
		a = b;
		b = a % temp;
	}
	return a;
}

int main(){
	int n, a, b;
	std::ifstream bem("euclid2.in");
	bem >> n;
	std::ofstream kim("euclid2.out");
	for(int i = 0; i < n; i++){
		bem >> a >> b;
		kim << lnko(a, b) << "\n";
		
	}
	bem.close();
	kim.close();
}
