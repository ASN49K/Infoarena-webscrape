#include<fstream>
#include<cstring>
using namespace std;

int cmmdc(int a, int b) {
  if (b==0) return a;	
  else return cmmdc(b, a%b);
}

int main(void) {
    ifstream cin("euclid2.in");
	ofstream cout("euclid2.out");
	
	int t, a, b;
	cin>>t;
	
	for (int i=1; i<=t; ++i) {
	   cin>>a>>b;
	   cout<<cmmdc(a,b)<<"\n";
    }
 	
	return 0;
}
