#include<fstream>
using namespace std;
ifstream fi("euclid2.in");
ofstream fo("euclid2.out");
int e(int a,int b){
	if(!b) return a;
	else return e(b,a%b);
}
long int a,b,t;
int main(){
	fi>>t;
	for(int i=1;i<=t;i++){
		fi>>a>>b;
		fo<<e(a,b)<<endl;;
	}
	fi.close();
	fo.close();
	return 0;
}
