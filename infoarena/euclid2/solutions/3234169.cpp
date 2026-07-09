#include <iostream>
#include <fstream>

int main(){
	int n, a, b;
	std::ifstream bem("euclid2.in");
	bem >> n;
	std::ofstream kim("euclid2.out");
	for(int i = 0; i < n; i++){
		bem >> a >> b;
		while(b != 0){
			int temp = a;
			a = b;
			b = a % temp;
		}
		kim << a << "\n";
	}
	bem.close();
	kim.close();
}
