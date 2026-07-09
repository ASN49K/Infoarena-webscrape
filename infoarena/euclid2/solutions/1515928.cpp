#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int gcd(int a, int b){
    if(b==0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main() {
    int n;
    f>>n;
    for(int i=0;i<n;i++){
        int a, b;
        f>>a;
        f>>b;
        g<<gcd(a,b)<<"\n";
    }
    return 0;
}
