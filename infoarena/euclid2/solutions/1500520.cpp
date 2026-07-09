#include<fstream>
using namespace std;

#define infile "euclid2.in"
#define outfile "euclid2.out"

inline int cmmdc(int a, int b){
	if(!b)
		return a;
	return cmmdc(b, a % b);
}

int main(){
	ifstream fin(infile);
	ofstream fout(outfile);
	
	int T, a, b;
	
	for(fin >> T; T; --T){
		fin >> a >> b;
		fout << cmmdc(a, b) << '\n';
	}
	
	fin.close()
	fout.close();
	
	return 0;
}