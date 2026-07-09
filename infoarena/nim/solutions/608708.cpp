#include <fstream>
using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int T,i,N,G,S;

int main() {
	for(fin >> T; T; T--) {
		fin >> N;
		S=0;
		for(i=1;i<=N;i++) {
			fin >> G;
			S=(S^G);
		}
		if(S==0) fout << "NU\n";
		else fout << "DA\n";
	}
}
