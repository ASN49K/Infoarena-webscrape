# include <fstream>
using namespace std;
int main(void){ ifstream f("euclid2.in"); ofstream f1("euclid2.out");
	long t,a,b;
	int i;
	f>>t;
	for(i=1;i<=t;i++){
		f>>a;
		f>>b;
		while(a!=b){
			if(a<b)
				b-=a;
			if(a>b)
				a-=b;
		}
		f1<<a<<'\n';
	}
	return 0;
}
	