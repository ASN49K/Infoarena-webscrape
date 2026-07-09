#include <iostream>
#include <fstream>

int lnko(int a, int b){
	while(b != 0){
		int temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

int main(){
	int n;
	std::ifstream bem("euclid2.in");
	std::ofstream kim("euclid2.out");
	bem >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		bem >> a >> b;
		kim << lnko(a, b) << "\n";
	}
	bem.close();
	kim.close();
}
