#include <fstream>
using namespace std;

class euclid {
    public:
    int x,y;
    inline void add(int,int);
    void cmmdc() {
        int c;
        while (y) {
            c=x%y;
            x=y;
            y=c;
        }
    }
};

void euclid::add(int a, int b) { x=a,y=b;}

int main()
{
    euclid e;
    int a,b,t;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for( ;t;t--) {
        f>>a>>b;
        e.add(a,b);
        e.cmmdc();
        g<<e.x<<'\n';
    }
    return 0;
}
