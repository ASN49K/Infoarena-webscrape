#include <fstream>
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a, int b){
    if(a==0) return b;
    else cmmdc(b%a, a);
}

int main(){
    int a, b, n;
    fin >> n;
    for(int i=1; i<=n; i++){
        fin >> a >> b;
        fout << cmmdc(a, b) << "\n";
    }
    return 0;
}
