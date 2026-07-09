#include <fstream>
int euclid(int a,int b){
	if (a == 0)return b;
	else return euclid(b%a, a);
}
int main(){
	std::ifstream f("euclid2.in");
	std::ofstream of("euclid2.out");
	int T, a, b;
	f >> T;;
	for (int i = 0; i < T; ++i){
		f >> a>>b;
		of << euclid(a, b) << "\n";
	}
	return 0;
}