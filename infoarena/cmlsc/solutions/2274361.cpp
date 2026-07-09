#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main(){
	int m,n,d=0;
	fin >> m >> n;
	int x[m],y[n],c[256];
	for(int i=0;i<m;i++)
		fin >> x[i];
	for(int j=0;j<n;j++)
		fin >> y[j];
	for(int a=0;a<m;a++){
		for(int b=0;b<n;b++){
			if(x[a] == y[b]){
				c[d] = x[a];
				d++;
			}
		}
	}
	fout << d << "\n";
	for(int p=0;p<d;p++){
		fout << c[p];
		if(p<d-1)
			fout << " ";
	}
	return 0;
}
