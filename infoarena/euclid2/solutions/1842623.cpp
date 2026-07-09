#include <fstream>

using namespace std;


int euclid2(long long a,long long b){
	while(a!=b)
	(a>b)? (a=a-b) : (b=b-a);
	return a;
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