#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,i,x[200001];
int cmmdc(int &a, int &b) {
    int r;
    while(b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
    }
int main()
{
    int nr,a,b;
    nr=2;
    fin>>n;
    while(nr<=2*n) {
        fin>>a>>b;
        nr+=2;
        fout<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
