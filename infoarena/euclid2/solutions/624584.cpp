#include<fstream>
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int t,a,b;
int main(){
f>>t;
for(;t;t--){
	f>>a;
	f>>b;
	
	while (a!=b)
		if (a>b)
			a-=b;
		else
			b-=a;
	g<<a<<"\n";
	
}

return 0;
}
	