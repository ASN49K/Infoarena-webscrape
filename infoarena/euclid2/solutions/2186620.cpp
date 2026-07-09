#include <fstream>
using namespace std;
int main(){
	ifstream input("euclid2.in");
	ofstream print("euclid2.out");
	int t , x , y;
	input>>t;
	while(t--){
		input>>x>>y;
		print<<__gcd(x,y)<<"\n";
	}
	return 0;
}