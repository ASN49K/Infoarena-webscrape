#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
void cmmdc(int a,int b) {
    int cmmdc=0;
    int Max;
    if(a>=b)
        Max=a;
    else if(a<b)
        Max=b;
    for(int i=Max; i>0; i--) {
        if(a%i==0&&b%i==0){
            cmmdc=i;
            break;
        }
    }
    fout<<cmmdc<<'\n';
}
int main() {
    int n,a,b;
    fin>>n;
    for(int i=0; i<n; i++) {
        fin>>a>>b;
        cmmdc(a,b);
    }
    return 0;
}
