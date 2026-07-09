#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b){
    if (a%b==0) return b;
    return cmmdc(b,a%b);
}


int main(){
    int a,b;
    fin>>a>>b;
    if (a>b) fout<<cmmdc(a,b);
    else fout<<cmmdc(b,a);
	return 0;
}
