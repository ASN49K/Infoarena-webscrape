#include <fstream>
using namespace std;
std::ifstream in ("euclid2.in"); std::ofstream out ("euclid2.out");

int euclid (unsigned int a, unsigned int b){
    if(b==0) return a;
    else euclid (b,a%b);
}

int main(){
    unsigned int x,a,b;

    in>>x;
    while(x--){
        in>>a>>b;
        out<<euclid(a,b);
        out<<"\n";
    }
    return 0;
}
