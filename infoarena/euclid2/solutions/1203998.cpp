#include<fstream>
using namespace std;
 long long T,a,b;
ifstream cin("euclid.in");
ofstream cout("euclid.out");
int cmmdc(int a, int b){
	if(!b) return a;
	return cmmdc(b,a%b);
}
int main() {
	cin>>T;
	 for(int i=1;i<=T;i++){
	     cin>>a>>b;
	     cout<<cmmdc(a,b)<<"\n"; }
	   cin.close();
	   cout.close();
	   return 0;
}
	     
	 
