#include<fstream>

using namespace std;


ifstream f("nim.in");
ofstream g("nim.out");

int T,n,a,b,i;

int main(){
	
	f>>T;
	
	while(T--){
		f>>n>>a;
		for(i=1;i<n;i++){
			f>>b;
			a^=b;
		}
		if(a==0)
			g<<"NU\n";
		else
			g<<"DA\n";
	}
	
	
	return 0;
}
