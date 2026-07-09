#include <fstream>
using namespace std;
int main(){
    long  T,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for (T; T; --T){
        f>>a>>b;
        while (b!=0){
              long r=a%b;
              a=b;
              b=r;
        } // while
    g<<a<<"\n"; 
    } // for
    f.close(); g.close();
    return 0;
}
    
