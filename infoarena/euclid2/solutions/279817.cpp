#include <fstream>
using namespace std;

int cmmdc(int a,int b){
	if(b==0) return a;
	else return cmmdc(b,a%b);
}


int main(){
	int n;
	int a,b;
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	in>>n;

	for(;n>0;n--){
		in>>a>>b;
//		while(a!=b){
//			if(b>a) {
//				if(b%a!=0) b%=a;
//				else b=a;
//			} else {
//				if(a%b!=0) a%=b;
//				else a=b;
//			}
//		}
		out<<cmmdc(a,b)<<endl;
	}
}
