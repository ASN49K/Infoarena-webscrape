#include <fstream>

int cmmdc(int a, int b){
    if(!b) return a;
    return cmmdc(b, a%b);
}

int main(){
    using namespace std;
    ofstream out("euclid.out");
    ifstream in("euclid.in");

    int a, b, n;
    in>>n;

    for(; n!=0 ;n--){
        in>>a>>b;
        out<<cmmdc(a,b)<<"\n";

    }
    return 0;
}
