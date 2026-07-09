
#include <fstream>
#define ui unsigned int
using namespace std;
ui cmmdc (ui a , ui b) {

    if(b) {
        return cmmdc(b,a%b);
    }
    else return a;

}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T;
    f>>T;
    for(int i=0;i<T;i++) {
        ui a,b;
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';

    }
    f.close();
    return 0;
}
