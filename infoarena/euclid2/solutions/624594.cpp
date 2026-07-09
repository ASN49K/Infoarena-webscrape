#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,r;
int main(){
f>>t;
for(;t;t--){
	f>>a;
	f>>b;
	
	while (b!=0){
		r=a%b;
		a=b;
		b=r;
		
	}
	g<<a<<"\n";
}
f.close();
g.close();
return 0;
}
	