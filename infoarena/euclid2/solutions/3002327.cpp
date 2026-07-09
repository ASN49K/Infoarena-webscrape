#include <fstream>
using namespace std;
ifstream f(".in");
ofstream g(".out");
int main(){
    int t;
    f>>t;
    while(t--){
        int a,b;
        f>>a>>b;
        while(b){
            int r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
    return 0;
}
