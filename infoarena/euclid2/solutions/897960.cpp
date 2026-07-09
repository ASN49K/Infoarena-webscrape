#include <fstream>
using namespace std;
int n, a, b;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int cmmdc(int a, int b)
{
    if (!b) return a;
    return cmmdc(b, a % b);
}

void cit(){
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
}

int main(){
    cit();
    fin.close();
    fout.close();
    return 0;
}
