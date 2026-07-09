#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()

{ int t,a,b,c,nr;
    f>>t;
    for(int i=1;i<=t;i++){
        f>>a>>b;
        while(b){
            c=a%b;
            a=b;
            b=c;

        }
        g<<a<<"\n";
    }
}
