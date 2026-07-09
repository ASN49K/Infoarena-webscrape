#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int T;
int main()
{   f>>T;
    while(T){
        int r,a,b;
        f>>a>>b;
        while(b){
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
        T--;
    }
}
