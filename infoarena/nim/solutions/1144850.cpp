#include <fstream>

int main(){
	std::ifstream fin("nim.in");
	std::ofstream fout("nim.out");

	int t; fin>>t;
	while(t--){
		unsigned n; fin>>n;
		unsigned xsum=0;
		for(unsigned i=0;i<n;++i){
			unsigned a; fin>>a;
			xsum^=a;
		}

		if(xsum!=0) fout<<"DA\n";
		else fout<<"NU\n";

	}

}
