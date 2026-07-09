
#include <fstream>
using namespace std;
#define ui unsigned int
ui cmmdc (ui a , ui b) {

    if(b) {
        return (b,a%b);
    }
    else return 0;

}
int main()
{
    ifstream f("euclid1.in");
    ofstream g("euclid2.out");
    int T;

    for(int i=0;i<T;i++) {
        ui a,b;
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;

    }
    f.close();
    return 0;
}
