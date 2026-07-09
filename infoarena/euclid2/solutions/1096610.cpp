#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a,int b){
    if (a%b==0) return b;
    return cmmdc(b,a%b);
}


int main(){
    int a,b,t;
    fin>>t;
    for (int i=0;i<t;i++){
        fin>>a>>b;
        if (a>b) fout<<cmmdc(a,b)<<"\n";
        else fout<<cmmdc(b,a)<<"\n";
    }
	return 0;
}
