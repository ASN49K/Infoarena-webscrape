#include <fstream>
using namespace std;
int main() {
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int a,b,r,p;
    f>>p;
    while(p>0){
    f>>a>>b;
    r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    g<<b<<"\n";
    p--;
    }
    return 0;
}
