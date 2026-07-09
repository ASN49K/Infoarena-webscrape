#include <fstream>
using namespace std;
int euclid(int x, int y){
    int c;
    while (y) {
        c = x % y;
        x = y;
        y = c;
    }
    return x;
}
int main(){
    int T,a,b,i;
    ifstream citeste("euclid2.in");
    ofstream scrie("euclid2.out");
    citeste>>T;
    for(i=1;i<=T;i++){
                      citeste>>a>>b;
                      scrie<<euclid(a,b)<<endl;
                      }
    return 0;
}
