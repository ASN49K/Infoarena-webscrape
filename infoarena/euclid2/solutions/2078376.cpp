#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T;
int main()
{   f>>T;
    int r,a,b;
    for(int i=1;i<=T;i++){
        f>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<"\n";
    }
}
