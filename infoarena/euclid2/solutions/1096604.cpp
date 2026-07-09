#include<fstream>
using namespace std;
int t,a,b;

int cmmdc(int a, int b) {
    int r;
    do {
        r=a%b;
        a=b;
        b=r;
        } while (r!=0);
    return(a);
}

int main(void) {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for (; t>0; --t) {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
        }
    return(0);
}
