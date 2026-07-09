#include <fstream>

using namespace std;

int a, b, T;

int cmmdc(int a, int b){
    if(!b) return a;
    return cmmdc(b, a % b);
}

int main(){
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f >> T;
    for(int i = 0;i < T;i++){
        f >> a >> b;
        g << cmmdc(a, b) << "\n";
    }
}
