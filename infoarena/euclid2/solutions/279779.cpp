#include <fstream>
using namespace std;

int main(){
	int n;
	int a,b;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	in>>n;

	for(;n>0;n--){
		in>>a>>b;
		while(a!=b){
			if(b>a) b-=a;
			else a-=b;
		}
		out<<a<<endl;
	}
}
