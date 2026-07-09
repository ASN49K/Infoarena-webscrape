#include <fstream>
#define input "euclid2.in"
#define output "euclid2.out"
using namespace std;
namespace file{
    ifstream f(input);
    ofstream g(output);
    void close(){
        f.close();
        g.close();
    }
}
int cmmdc(int a, int b){
    int t;
    while(b) t=a%b, a=b, b=t;
    return a;
}

int main(){
    int n, a, b;
    file::f>>n;
    for(int i=1;i<=n;i++){
        file::f>>a>>b;
        file::g<<cmmdc(a,b)<<'\n';
    }
    file::close();
    return 0;
}
