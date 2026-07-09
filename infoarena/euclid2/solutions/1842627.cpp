#include <fstream>

using namespace std;


int euclid2(int a,int b){
	int c;
	while(b){
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}



int main(){
	ifstream file("euclid2.in");
	ofstream file_o("euclid2.out");
	int it,a,b;
	file>>it;
	for(int i=0;i<it;i++){
		file>>a>>b;
		file_o<<euclid2(a,b)<<endl;
	}

}