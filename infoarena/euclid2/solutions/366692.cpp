#include <fstream>
using namespace std;

int main(){
    int T,a,b,i,c;
    ifstream citeste("euclid2.in");
    ofstream scrie("euclid2.out");
    citeste>>T;
    for(i=1;i<=T;i++){
                      citeste>>a>>b;
                      while (b) {
                            c = a % b;
                            a = b;
                            b = c;
                            }
                      scrie<<b;
                      }
    return 0;
}
