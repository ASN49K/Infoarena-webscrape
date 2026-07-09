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
			if(b>a) {
				if(b%a!=0) b%=a;
				else b=a;
			} else {
				if(a%b!=0) a%=b;
				else a=b;
			}
		}
		out<<a<<endl;
	}
}
