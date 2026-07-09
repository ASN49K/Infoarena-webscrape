# include <fstream>
using namespace std;
int main(void){ 
	ifstream f("euclid2.in"); 
	ofstream f1("euclid2.out");
	long t,a,b,r;
	int i;
	f>>t;
	for(i=1;i<=t;i++){
		f>>a;
		f>>b;
		while(b!=0){
			r=a%b;
			a=b;
			b=r;
		}
		f1<<a<<'\n';
	}
	f.close();
	f1.close();
	return 0;
}
	