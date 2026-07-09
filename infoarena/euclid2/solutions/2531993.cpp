#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int q, a, b;

int cmmdc(int a, int b){
    int r=0;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    f >> q;
    while(q--){
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
    return 0;
}
