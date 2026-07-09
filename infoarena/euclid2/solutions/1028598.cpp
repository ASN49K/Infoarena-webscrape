#include <fstream>
using namespace std;
ifstream in ("euclcid2.in");
ofstream out("euclid2.out");
int main (){
	int t,a,b,r,cmmdc;
	in>>t;
	while(t--)
		in>>a>>b;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	cmmdc=a;
	out<<cmmdc<<"\n";
	return 0;
}
