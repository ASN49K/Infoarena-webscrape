#include <fstream>
#define MAX 100001
using namespace std;

int euclid(int a, int b){
	if(b > a)
		swap(a, b);

	if(b == 0)
		return a;
	else
		return euclid(b, a % b);
}

int main(){
	ifstream fin;
	ofstream fout;
	fin.open("euclid2.in");
	fout.open("euclid2.out"); 
	int n, a, b;

	fin >> n;
	for(int i=0; i < n; ++i){
		fin >> a >> b;
		fout << euclid(a, b) << "\n";
	}

}