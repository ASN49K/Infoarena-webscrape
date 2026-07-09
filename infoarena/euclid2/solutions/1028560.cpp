#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");	
int main(){
	int t,a,b,r;
	in>>t;
	while(t--){
		in>>a>>b;
		while(b!=0){
			r=a%b;
			a=b;
			b=r;
		}
		out<<a<<endl;
	}
	return 0;
}
