#include <fstream>

using namespace std;


int euclid2(long long a,long long b){
	if(b==0) return a;
	else return euclid2(b,b%a);
}



int main(){
	ifstream file("euclid2.in");
	ofstream file_o("euclid2.out");
	long long it,a,b;
	file>>it;
	for(int i=0;i<it*2;i+=2){
		file>>a>>b;
		file_o<<euclid2(a,b)<<endl;
	}

}