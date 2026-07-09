#include <fstream>
using namespace std;
ifstream cin("euclid2.in");
ofstream cout("euclid2.out");
int t,a,b;

int _gcd(int a,int b){
	return b==0 ? a : _gcd(b,a%b);
}

int main(void) { 
 cin>>t;
 while(t--){
 	cin>>a>>b;
 	cout<<_gcd(a,b)<<"\n";
 }
 return 0;
}


